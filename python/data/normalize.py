"""
Timestamp/data normalization for Stage 2.

Input CSV columns:
    timestamp,symbol,price,volume

This module normalizes each row into:
    - UTC timestamp
    - uppercase symbol
    - float price
    - float volume
"""

from __future__ import annotations

from dataclasses import dataclass
from datetime import datetime, timezone


@dataclass
class NormalizedRecord:
    timestamp_utc: datetime
    symbol: str
    price: float
    volume: float


def normalize(raw_row: dict) -> NormalizedRecord:
    timestamp = str(raw_row["timestamp"]).strip()

    # Unix timestamp
    if timestamp.isdigit():
        dt = datetime.fromtimestamp(int(timestamp), tz=timezone.utc)

    # ISO / normal datetime formats
    else:
        timestamp = timestamp.replace("Z", "+00:00")

        try:
            dt = datetime.fromisoformat(timestamp)
        except ValueError:
            dt = datetime.strptime(timestamp, "%m/%d/%Y %H:%M:%S")

        # Assume timestamps without timezone information are UTC for now.
        if dt.tzinfo is None:
            dt = dt.replace(tzinfo=timezone.utc)

        dt = dt.astimezone(timezone.utc)

    volume = raw_row.get("volume")

    return NormalizedRecord(
        timestamp_utc=dt,
        symbol=str(raw_row["symbol"]).strip().upper(),
        price=float(raw_row["price"]),
        volume=float(volume) if volume else 0.0,
    )