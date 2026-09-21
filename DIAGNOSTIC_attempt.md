# Diagnostic Assessment — Week 1 Baseline

**Do not look up answers while attempting this.** The point is to establish an honest
baseline, not a score. Answers are not provided until after you submit your attempt — write
out real attempts (a sentence or two is fine for conceptual questions; actual code/pseudocode
for the code questions) and submit them back. Budget ~1.5-2 hours.

This baseline will be re-run in an abbreviated form at Weeks 8 and 16 to track real movement.

---

## C++ (8)

1. Explain the difference between stack and heap allocation. When would you choose one over
   the other in a performance-sensitive system?
        Stack is living in the queue that things are executed in. heap lives in memory. heap is faster but cant have much in it.
2. What does RAII mean and why does it matter in C++? Give an example of a bug it prevents.
        Is ita memory management system so that you know when to clean up pointers
3. What is the Rule of Five? When is the Rule of Zero preferable?
        a function should not be doing more than 5 things
4. Explain move semantics: what does `std::move` actually do (or not do)?
        moves the pointer of an object somewhere else
5. What is undefined behavior? Give two concrete examples of UB in C++.
        When a function is being called that doesnt exist and when a function is being called that has nothing inside of it
6. What's the difference between `const int*`, `int* const`, and `const int* const`?
        const int* is a pointer to a int that is constant
        int* const is the same
        const int* const is a pointer to an int thats also pointing to a const int
7. What does `virtual` do, roughly, at the machine level? What is a vtable?
        it creates a system link to a varaible
8. Sketch (pseudocode is fine) a function template that returns the max of two values of any
   comparable type. What could go wrong with type deduction here?
        i know there an ambiguous type that i can use in place of anything to compare objects i just forget
        object (o1,o2){
            if o1 > o2:
            return 21
            else 
            return o2
        }
        should type cast it into something here as well or use the override methods for .compare or .gt


## Python (5)

9. Explain what the GIL is — what it does and does not protect you from.
        Its the tabbing system to determine scope
10. What's the difference between a generator and a list comprehension in terms of memory
    behavior?
        a generoteor generators a list while a list comprehension inteprets it just reading instead of writing to memory
11. Explain Python's reference counting and where cycles cause a problem.
        a reference outing means it keeps track of references in a scope
12. When would you reach for `multiprocessing` vs. `threading` vs. `asyncio`? Give one
    deciding criterion for each.
        asyncio when multiple things are coming in like a load balancer sending off different workers
        threading when stuff can happen at the same time but wont affect each other
        multiprocessing when you can exectute multiple things at once on different cores
13. What is a decorator? Sketch a simple one that times a function's execution.
        its like a parent of an object

## Rust — familiarity level only (3)

14. What problem does the borrow checker solve that C++ leaves entirely to the programmer?
    it makes sure that memory that is borrowed in a scope is later cleaned up
15. What's the practical difference between `Box<T>`, `Rc<T>`, and `Arc<T>`?
they all have different override functions but are the same parent
16. What does it mean, roughly, for a type to be `Send` vs. `Sync`?
    send a request vs get/sync a request

## Linux / Networking (4)

17. What's the difference between a process and a thread in terms of what's shared and what
    isn't?
        process owns it resources threads can share resources
18. Explain the difference between TCP and UDP, and why one might be preferred for market
    data distribution.
        tcp has larger packet checking to make sure its ok udp just sends packets through
19. What does `epoll` solve that `select`/`poll` don't?
    epoll is continious select/pool is a one time try
20. What is virtual memory, and why do programs get to behave as if they have a contiguous
    address space?
        because continious space is allocated to them but virtual memory is just the space their allocated at first

## Concurrency / CPU / Cache (4)

21. What is a cache line, and how does false sharing happen?
    Cache is storing data for wuick look up from multiple programs but if two write at the same time it ruins the data
22. Explain the difference between a mutex and an atomic operation. When would you use each?
    mutex protects the data atomic stops everything you would use mutex for single threads to keep save while atomic is a whole program wide through
23. In one or two sentences: what do "acquire" and "release" memory ordering mean?
    quire means to protect memory that your activily using release means to release it back to the operating system cause it can be written over again
24. What is branch prediction, and why does it matter for hot-path code?
    cause it needs to know which path in the cpi to take to make sure its going faster since that branch is being used constantyl

## Algorithms / Performance (3)

25. What's the time/space complexity of a hash map you're comfortable with, and what causes
    worst-case degradation?
    o(1)
26. What's the difference between latency and throughput? What is p99 latency, and why does
    it matter more than average latency in a trading system?
    Latency is how long is takes for a io to go through throughput is how many can go through. 
27. Name one thing you'd measure *before* optimizing a piece of code, and one tool you'd use
    to measure it.
    probably latency of an io going through idk what tool to use through

## Trading-system concepts (4)

28. What is a limit order book? What do "price-time priority" and "price levels" mean?
        limit book keeps track of limit orders in a buying system. pricetime priority means its prioirtizes price then when that price cvame in to fill an order closest to it. price levels means it could be a could std a way from the prioce
29. From the matching engine's perspective, what's the structural difference between how a
    market order and a limit order get handled?
    first it goes market order as market orders can be at any price then limit if theres a proper order to limit but if someone is selling at buy at the price given it goes that route
30. What is slippage, and why does it matter for backtesting?
    is it when the price your quote changes before you can fill it so you have to pay the difference
31. Name one form of bias that can make a backtest look better than a live strategy would
    actually perform, and explain it in one sentence.
        its overfitted on old historical data instead of actually predicting change.

---

**Submission:** paste your attempt back in the conversation, or write it to
`05-admin/diagnostic_attempt.md`. Once submitted, the weekly review will go through it —
expect follow-up oral questions on at least a few answers rather than a flat score.
