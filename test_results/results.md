All tests were done with wrk in loopback. Wrk used 4 threads and 100 connections. Each test took 1 minute.

## Syncronous

### test1:

```
4 threads and 100 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency    11.40ms    4.90ms  63.35ms   72.06%
    Req/Sec     1.40k   185.63     1.96k    73.52%
  Latency Distribution
     50%   10.92ms
     75%   14.13ms
     90%   17.47ms
     99%   25.73ms
  333642 requests in 1.00m, 18.14MB read
Requests/sec:   5551.41
Transfer/sec:    309.01KB
```

### test2:

```
4 threads and 100 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency    12.38ms    6.60ms 149.21ms   80.11%
    Req/Sec     1.33k   213.52     1.93k    77.62%
  Latency Distribution
     50%   11.56ms
     75%   15.10ms
     90%   19.06ms
     99%   33.69ms
  317132 requests in 1.00m, 17.24MB read
Requests/sec:   5278.25
Transfer/sec:    293.81KB
```

### test3:

```
4 threads and 100 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency    14.04ms    8.74ms 177.29ms   82.80%
    Req/Sec     1.20k   283.65     2.00k    70.74%
  Latency Distribution
     50%   12.46ms
     75%   16.77ms
     90%   22.92ms
     99%   46.12ms
  286029 requests in 1.00m, 15.55MB read
Requests/sec:   4760.95
Transfer/sec:    265.01KB
```

### test4:

```
4 threads and 100 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency    13.36ms    7.35ms 108.80ms   79.91%
    Req/Sec     1.23k   249.51     1.84k    75.01%
  Latency Distribution
     50%   12.20ms
     75%   16.13ms
     90%   21.01ms
     99%   40.65ms
  292903 requests in 1.00m, 15.92MB read
Requests/sec:   4875.24
Transfer/sec:    271.38KB
```

## Thread per connection

### test1:

```
4 threads and 100 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency    55.19ms   51.17ms   1.10s    92.69%
    Req/Sec   457.57    197.80     1.08k    65.27%
  Latency Distribution
     50%   45.02ms
     75%   64.61ms
     90%   91.64ms
     99%  244.28ms
  108282 requests in 1.00m, 5.89MB read
Requests/sec:   1801.52
Transfer/sec:    100.28KB
```

### test2:

```
4 threads and 100 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency    58.57ms   74.19ms 963.76ms   90.58%
    Req/Sec   498.09    281.51     1.27k    64.30%
  Latency Distribution
     50%   35.77ms
     75%   57.12ms
     90%  124.97ms
     99%  371.67ms
  117359 requests in 1.00m, 6.38MB read
Requests/sec:   1952.74
Transfer/sec:    108.70KB
```

## Thread Pool with 10 threads

```
4 threads and 100 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency   102.38ms    6.15ms 188.46ms   95.10%
    Req/Sec   243.11     16.71   303.00     91.19%
  Latency Distribution
     50%  101.43ms
     75%  102.14ms
     90%  103.34ms
     99%  132.62ms
  58140 requests in 1.00m, 3.16MB read
Requests/sec:    967.82
Transfer/sec:     53.87KB
```

## Event loop

```
 4 threads and 100 connections
  Thread Stats   Avg      Stdev     Max   +/- Stdev
    Latency    11.86ms    6.44ms  93.12ms   72.97%
    Req/Sec     1.28k   246.81     2.68k    73.31%
  Latency Distribution
     50%   10.93ms
     75%   15.15ms
     90%   19.81ms
     99%   32.59ms
  306401 requests in 1.00m, 16.66MB read
Requests/sec:   5100.16
Transfer/sec:    283.90KB
```