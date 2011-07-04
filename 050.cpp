#include <iostream>
#include <deque>
#include <cstdint>
#include "euler.hpp"


int main(void)
{
    std::deque<uint16_t> primes;
    uint16_t p, max_length = 0;
    uint32_t sum, max_sum = 0;
    const uint32_t limit = 999999;

    /**
     * First, generate the longest sum of consecutive primes, below 1000000,
     * starting at 2.
     */
    // first two primes
    primes.push_back(2);
    primes.push_back(3);
    // sum at this point is 2 + 3
    sum = 5;
    // generate primes >= 5
    for (p = 5; ; p += (p % 6 == 5) ? 2 : 4) {
        if (primes.size() > max_length && euler::is_prime(sum)) {
            max_sum = sum;
            max_length = primes.size();
        }
        if (!euler::is_prime(p))
            continue;
        if (sum + p > limit)
            break;
        primes.push_back(p);
        sum += p;
    }

    /**
     * At each iteration of the outer loop, delete the first term from the sum
     * starting at 2. In the inner loop, try to add more primes until the sum
     * reaches the limit. In other words, implement a sliding window on the set
     * of prime numbers where the window size is equal to 999999.
     *
     * Note that since the primes are getting larger and larger, the number of
     * terms needed to reach a sum near 1000000 will decay. Generate primes
     * until the number of terms decay to half of the current maximum sum length.
     */
    while (primes.size() > max_length / 2) {
        // delete first term from sum
        sum -= primes.front();
        primes.pop_front();

        // generate primes > last term
        p = primes.back() + ((primes.back() % 6 == 5) ? 2 : 4);
        for (; primes.size() > max_length / 2; p += (p % 6 == 5) ? 2 : 4) {
            // we only check the sum if the number of terms exceed the current
            // max_length.
            if (primes.size() > max_length && euler::is_prime(sum)) {
                max_sum = sum;
                max_length = primes.size();
            }
            if (!euler::is_prime(p))
                continue;
            if (sum + p > limit)
                break;
            primes.push_back(p);
            sum += p;
        }
    }

    std::cout << max_sum << std::endl;

    return 0;
}
