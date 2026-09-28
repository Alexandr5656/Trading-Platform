"""
Timestamp/data normalization for a market-data source (Stage 2 on-ramp).

TODO: pick a data source (placeholder CSV, synthetic series, or a real
free source) and describe it here: what it is, what shape it arrives in,
and what this module normalizes it into (e.g. a common OHLCV schema with
UTC-normalized timestamps).

Doesn't need to be complete or tested yet -- this is the Week 2 on-ramp,
full Stage 2 build-out comes later.
"""

from __future__ import annotations

from dataclasses import dataclass


@dataclass
class NormalizedRecord:
    # TODO: define the normalized shape this module produces, e.g.:
    # timestamp_utc: datetime
    # symbol: str
    # price: float
    # volume: float
    pass


def normalize(raw_row: dict) -> NormalizedRecord:
    """TODO: convert one raw row from the chosen source into a NormalizedRecord."""
    raise NotImplementedError
