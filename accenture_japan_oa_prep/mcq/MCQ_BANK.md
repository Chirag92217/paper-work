# MCQ Practice Bank

98 questions on the topics reported in past Accenture Japan OAs: OS, CN, DBMS, OOP, DSA, Cloud, Security, Web/AI.
Cover the answers, attempt a full section, then check. Aim for **≥ 85%** before the OA. In past reports, MCQ accuracy mattered a lot for shortlisting.

| Topic | Questions |
|---|---|
| Operating Systems | 16 |
| Computer Networks | 15 |
| DBMS & SQL | 13 |
| OOP | 8 |
| DSA & Complexity | 17 |
| Cloud & DevOps | 13 |
| Security | 6 |
| Web, AI & Software Engineering | 10 |

---

## Operating Systems

**1. Which of these is shared by all threads of the same process?**

- (A) Register set
- (B) Stack
- (C) Heap and global data (the address space)
- (D) Program counter

<details><summary>Answer</summary>

**C**: Each thread has its own stack, PC and registers. Code, heap, globals and open files are shared.

</details>

**2. Which of these is NOT one of the four necessary conditions for deadlock?**

- (A) Mutual exclusion
- (B) Hold and wait
- (C) Circular wait
- (D) Preemption of resources

<details><summary>Answer</summary>

**D**: The condition is NO preemption. If resources can be preempted, deadlock cannot happen.

</details>

**3. The Banker's algorithm is used for:**

- (A) Deadlock prevention
- (B) Deadlock avoidance
- (C) CPU scheduling
- (D) Deadlock detection and recovery

<details><summary>Answer</summary>

**B**: It grants a request only if the system stays in a safe state, which is avoidance. Prevention breaks one of the four conditions.

</details>

**4. Four processes all arrive at time 0 with burst times 6, 8, 7, 3. What is the average waiting time under non-preemptive SJF?**

- (A) 8.75
- (B) 6
- (C) 7
- (D) 10.25

<details><summary>Answer</summary>

**C**: The order is 3, 6, 7, 8, so the waits are 0, 3, 9, 16 and the average is 28/4 = 7. FCFS would give 10.25.

</details>

**5. Belady's anomaly (more frames causing MORE page faults) can happen with:**

- (A) Optimal page replacement
- (B) FIFO page replacement
- (C) LRU page replacement
- (D) Any stack-based algorithm

<details><summary>Answer</summary>

**B**: LRU and Optimal are stack algorithms and never show Belady's anomaly. FIFO can.

</details>

**6. Reference string 7 0 1 2 0 3 0 4 with 3 frames under LRU. How many page faults?**

- (A) 7
- (B) 4
- (C) 6
- (D) 5

<details><summary>Answer</summary>

**C**: Faults on 7, 0, 1, 2, 3 and 4. The two later 0s are hits.

</details>

**7. Thrashing means:**

- (A) The CPU is idle because no process is ready
- (B) A process uses up its time slice too often
- (C) Two processes wait for each other forever
- (D) The system spends more time swapping pages than doing useful work

<details><summary>Answer</summary>

**D**: It is caused by too little memory for the working sets. Fix it by lowering the degree of multiprogramming or by using a working-set model.

</details>

**8. The main difference between a mutex and a binary semaphore is:**

- (A) There is no difference
- (B) A mutex has ownership: only the thread that locked it should unlock it
- (C) A mutex can be used for signalling between processes but a semaphore cannot
- (D) A semaphore can only take the values 0 and 1

<details><summary>Answer</summary>

**B**: Semaphores are signalling tools that any thread can post. A mutex is a lock owned by one thread.

</details>

**9. 32-bit virtual addresses, 4 KB pages. How many entries are in a single-level page table?**

- (A) 2^12
- (B) 2^32
- (C) 2^20
- (D) 2^10

<details><summary>Answer</summary>

**C**: 4 KB = 2^12, so the offset uses 12 bits. That leaves 20 bits for the page number, so 2^20 entries.

</details>

**10. Why is a context switch between threads of the same process cheaper than between processes?**

- (A) Threads do not have registers
- (B) Threads share the same stack
- (C) Threads never need the kernel
- (D) The address space stays the same, so there is no page-table switch or TLB flush

<details><summary>Answer</summary>

**D**: The thread switch still saves and restores registers and the stack pointer, but the memory mapping does not change.

</details>

**11. Round Robin with a very large time quantum behaves like:**

- (A) Shortest Remaining Time First
- (B) FCFS
- (C) SJF
- (D) Priority scheduling

<details><summary>Answer</summary>

**B**: If no process ever uses up its quantum, processes simply run in arrival order.

</details>

**12. Starvation in priority scheduling is usually fixed with:**

- (A) Spooling
- (B) Paging
- (C) Thrashing
- (D) Aging

<details><summary>Answer</summary>

**D**: Aging slowly raises the priority of processes that have waited a long time.

</details>

**13. Paging can suffer from which kind of fragmentation?**

- (A) Neither
- (B) Both internal and external equally
- (C) Internal fragmentation
- (D) External fragmentation

<details><summary>Answer</summary>

**C**: The last page of a process may be partly empty (internal). Paging removes external fragmentation. Segmentation suffers from external fragmentation.

</details>

**14. A zombie process is a process that:**

- (A) Is still running after its parent has died
- (B) Uses 100% CPU without doing anything
- (C) Has finished, but its parent has not yet called wait() to read its exit status
- (D) Is stuck in a deadlock

<details><summary>Answer</summary>

**C**: A running child whose parent has died is an orphan, and init/systemd adopts it.

</details>

**15. A program calls fork() three times in a row and then prints "hi" once. How many times is "hi" printed?**

- (A) 3
- (B) 6
- (C) 4
- (D) 8

<details><summary>Answer</summary>

**D**: Each fork doubles the number of processes: 2^3 = 8.

</details>

**16. Which of these is NOT a requirement for a correct critical-section solution?**

- (A) The shortest process must enter first
- (B) Mutual exclusion
- (C) Progress
- (D) Bounded waiting

<details><summary>Answer</summary>

**A**: The three requirements are mutual exclusion, progress and bounded waiting.

</details>

---

## Computer Networks

**17. The TCP three-way handshake is:**

- (A) SYN → SYN-ACK → ACK
- (B) SYN → SYN → ACK
- (C) SYN → ACK → FIN
- (D) ACK → SYN → SYN-ACK

<details><summary>Answer</summary>

**A**: FIN is used to close the connection, which takes a four-way exchange.

</details>

**18. DNS queries normally use:**

- (A) Port 25 over TCP
- (B) Port 53, mostly over UDP
- (C) Port 80 over TCP
- (D) Port 443 over UDP

<details><summary>Answer</summary>

**B**: DNS falls back to TCP for large responses and zone transfers.

</details>

**19. A router mainly works at which OSI layer?**

- (A) Physical layer (Layer 1)
- (B) Network layer (Layer 3)
- (C) Transport layer (Layer 4)
- (D) Data link layer (Layer 2)

<details><summary>Answer</summary>

**B**: Routers forward packets by IP address. Switches forward frames by MAC address (Layer 2).

</details>

**20. Which protocol is connectionless?**

- (A) FTP
- (B) TCP
- (C) HTTP/1.1 over TCP
- (D) UDP

<details><summary>Answer</summary>

**D**: UDP has no handshake, no guaranteed delivery and no ordering. It is used for DNS, video calls and games.

</details>

**21. Which HTTP status code means "you are identified, but you are not allowed to do this"?**

- (A) 403 Forbidden
- (B) 404 Not Found
- (C) 401 Unauthorized
- (D) 400 Bad Request

<details><summary>Answer</summary>

**A**: 401 means you are not authenticated or your credentials are bad. 403 means you are authenticated but not permitted.

</details>

**22. How many usable host addresses are there in a /26 IPv4 subnet?**

- (A) 64
- (B) 62
- (C) 126
- (D) 30

<details><summary>Answer</summary>

**B**: 2^(32−26) = 64. Subtract the network and broadcast addresses to get 62.

</details>

**23. Which protocol finds the MAC address for a known IPv4 address?**

- (A) ICMP
- (B) DNS
- (C) DHCP
- (D) ARP

<details><summary>Answer</summary>

**D**: DHCP assigns IP addresses, DNS turns names into IPs, and ICMP is used by ping and traceroute.

</details>

**24. Which HTTP method is idempotent?**

- (A) PATCH
- (B) PUT
- (C) None of them
- (D) POST

<details><summary>Answer</summary>

**B**: Sending the same PUT again leaves the resource in the same state. POST may create duplicates. PATCH is not guaranteed to be idempotent.

</details>

**25. TCP flow control is done with:**

- (A) Checksums
- (B) The receiver's advertised window (sliding window)
- (C) Slow start
- (D) Three-way handshake

<details><summary>Answer</summary>

**B**: Flow control protects the receiver. Congestion control (slow start, cwnd) protects the network.

</details>

**26. Which address is a private IPv4 address?**

- (A) 11.0.0.1
- (B) 8.8.8.8
- (C) 172.32.1.1
- (D) 192.168.10.5

<details><summary>Answer</summary>

**D**: The private ranges are 10.0.0.0/8, 172.16.0.0/12 (172.16–172.31) and 192.168.0.0/16.

</details>

**27. In the OSI model, which layer is traditionally responsible for encryption and data formatting?**

- (A) Presentation layer
- (B) Session layer
- (C) Transport layer
- (D) Application layer

<details><summary>Answer</summary>

**A**: Session manages dialogues between applications. In TCP/IP, both are merged into the application layer.

</details>

**28. How many bits long is an IPv6 address?**

- (A) 128
- (B) 32
- (C) 64
- (D) 256

<details><summary>Answer</summary>

**A**: IPv4 is 32 bits and IPv6 is 128 bits.

</details>

**29. "Each request carries everything the server needs, and the server stores no client session" describes which REST principle?**

- (A) Layered system
- (B) Cacheability
- (C) Uniform interface
- (D) Statelessness

<details><summary>Answer</summary>

**D**: Statelessness makes horizontal scaling easy, because any server can handle any request.

</details>

**30. During a TLS handshake, the shared symmetric session key is set up using:**

- (A) The server's password
- (B) An asymmetric key exchange such as (EC)DHE
- (C) A hash of the URL
- (D) The MAC address

<details><summary>Answer</summary>

**B**: Asymmetric cryptography sets up the key. Symmetric cryptography (such as AES) then encrypts the bulk data, because it is fast.

</details>

**31. What does a switch use to forward frames?**

- (A) Domain name
- (B) Destination IP address
- (C) Port number
- (D) Destination MAC address

<details><summary>Answer</summary>

**D**: A hub repeats each frame to all ports. A switch learns MAC addresses and sends frames only to the right port.

</details>

---

## DBMS & SQL

**32. In ACID, "Isolation" means:**

- (A) Concurrent transactions do not see each other's intermediate, uncommitted effects
- (B) A transaction runs completely or not at all
- (C) Once committed, data survives crashes
- (D) Data always satisfies the constraints

<details><summary>Answer</summary>

**A**: The wrong options describe Durability, Atomicity and Consistency.

</details>

**33. Third Normal Form (3NF) mainly removes:**

- (A) Multivalued dependencies
- (B) Repeating groups
- (C) Transitive dependencies of non-key attributes on the key
- (D) Partial dependencies on part of a composite key

<details><summary>Answer</summary>

**C**: 1NF removes repeating groups, 2NF removes partial dependencies, 3NF removes transitive dependencies, and 4NF removes multivalued dependencies.

</details>

**34. A relation is in BCNF if, for every non-trivial functional dependency X → Y:**

- (A) Y is a prime attribute
- (B) Y is not null
- (C) X is a superkey
- (D) X is a primary key column

<details><summary>Answer</summary>

**C**: 3NF also allows Y to be prime. BCNF does not, so it is stricter.

</details>

**35. Which join returns every row of the left table, with NULLs where there is no match?**

- (A) INNER JOIN
- (B) RIGHT OUTER JOIN
- (C) LEFT OUTER JOIN
- (D) CROSS JOIN

<details><summary>Answer</summary>

**C**: INNER JOIN keeps only matching rows.

</details>

**36. Table A has 3 rows and table B has 4 rows. How many rows does A CROSS JOIN B return?**

- (A) 7
- (B) 3
- (C) 12
- (D) 4

<details><summary>Answer</summary>

**C**: A cross join is the Cartesian product: 3 × 4.

</details>

**37. What is the difference between WHERE and HAVING?**

- (A) WHERE filters rows before grouping. HAVING filters groups after aggregation.
- (B) HAVING runs before GROUP BY
- (C) They are the same
- (D) WHERE can use aggregate functions such as COUNT()

<details><summary>Answer</summary>

**A**: You cannot write WHERE COUNT(*) > 5. Use HAVING for that.

</details>

**38. Which command removes the table's data AND its structure?**

- (A) TRUNCATE
- (B) DELETE
- (C) ALTER
- (D) DROP

<details><summary>Answer</summary>

**D**: DELETE removes rows (optionally with WHERE, and can be rolled back). TRUNCATE quickly removes all rows but keeps the table.

</details>

**39. Adding an index to a column usually:**

- (A) Makes reads/lookups faster but makes inserts and updates slower
- (B) Makes all operations faster
- (C) Makes reads slower and writes faster
- (D) Has no effect on performance

<details><summary>Answer</summary>

**A**: The index (often a B+ tree) must be updated on every write.

</details>

**40. A primary key column must be:**

- (A) Unique and NOT NULL
- (B) Any column with an index
- (C) An integer
- (D) Unique but can be NULL

<details><summary>Answer</summary>

**A**: A foreign key can contain duplicates and, unless it is constrained, NULLs.

</details>

**41. A "dirty read" is:**

- (A) Reading data written by another transaction that has not committed yet
- (B) Reading deleted rows
- (C) Reading a row twice and getting different values
- (D) New rows appearing when a range query is repeated

<details><summary>Answer</summary>

**A**: Dirty reads are prevented from READ COMMITTED upwards. The wrong options describe a non-repeatable read and a phantom read.

</details>

**42. Which query returns the second-highest salary?**

- (A) SELECT SECOND(salary) FROM emp;
- (B) SELECT MAX(salary) - 1 FROM emp;
- (C) SELECT MAX(salary) FROM emp WHERE salary < (SELECT MAX(salary) FROM emp);
- (D) SELECT salary FROM emp ORDER BY salary LIMIT 2;

<details><summary>Answer</summary>

**C**: Another way is ORDER BY salary DESC with LIMIT 1 OFFSET 1 on DISTINCT salaries.

</details>

**43. COUNT(column) differs from COUNT(*) because:**

- (A) There is no difference
- (B) COUNT(column) counts only distinct values
- (C) COUNT(column) ignores NULL values in that column
- (D) COUNT(*) ignores NULL rows

<details><summary>Answer</summary>

**C**: COUNT(DISTINCT column) is the one that counts distinct values.

</details>

**44. How many clustered indexes can a table have?**

- (A) One per column
- (B) Exactly two
- (C) At most one
- (D) Unlimited

<details><summary>Answer</summary>

**C**: A clustered index sets the physical order of the rows, and rows can only be stored in one order.

</details>

---

## OOP

**45. Runtime polymorphism is achieved through:**

- (A) Method overriding (virtual functions)
- (B) Templates/generics
- (C) Operator overloading
- (D) Method overloading

<details><summary>Answer</summary>

**A**: Overloading is resolved at compile time. Overriding is chosen at runtime through the vtable.

</details>

**46. When is method overloading resolved?**

- (A) At link time only
- (B) At runtime
- (C) Never
- (D) At compile time

<details><summary>Answer</summary>

**D**: The compiler picks the overload from the argument types.

</details>

**47. In Java, what can an abstract class have that an interface cannot?**

- (A) Constructors and instance (non-static) fields
- (B) Abstract methods
- (C) Static methods
- (D) Public methods

<details><summary>Answer</summary>

**A**: Since Java 8, interfaces can have default and static methods, but they still cannot have instance state or constructors.

</details>

**48. Encapsulation is best described as:**

- (A) Creating many objects from one class
- (B) Bundling data with the methods that use it, and restricting direct access to that data
- (C) Hiding implementation behind an interface for multiple types
- (D) Inheriting behaviour from a parent class

<details><summary>Answer</summary>

**B**: Abstraction is about showing only what is essential. Encapsulation is about protecting internal state.

</details>

**49. In C++, the "diamond problem" of multiple inheritance is solved with:**

- (A) Virtual inheritance
- (B) Virtual functions
- (C) Friend classes
- (D) Templates

<details><summary>Answer</summary>

**A**: With class B : virtual public A and class C : virtual public A, class D gets only one shared A subobject.

</details>

**50. "A class should have only one reason to change" is which SOLID principle?**

- (A) Single Responsibility Principle
- (B) Liskov Substitution Principle
- (C) Open/Closed Principle
- (D) Dependency Inversion Principle

<details><summary>Answer</summary>

**A**: S = Single responsibility, O = Open/closed, L = Liskov, I = Interface segregation, D = Dependency inversion.

</details>

**51. The Liskov Substitution Principle says:**

- (A) Clients should not depend on methods they don't use
- (B) Classes should be open for extension
- (C) A class should depend on abstractions
- (D) Objects of a subclass should be usable wherever the base class is expected, without breaking correctness

<details><summary>Answer</summary>

**D**: The classic violation is Square extends Rectangle, where setting the width changes the height.

</details>

**52. The Singleton pattern makes sure that:**

- (A) A class cannot be inherited
- (B) Objects are created only through subclasses
- (C) Every method is static
- (D) A class has only one instance, with a global access point

<details><summary>Answer</summary>

**D**: In multithreaded code, the instance must be created in a thread-safe way.

</details>

---

## DSA & Complexity

**53. What is the worst-case time complexity of quicksort?**

- (A) O(n)
- (B) O(n^2)
- (C) O(log n)
- (D) O(n log n)

<details><summary>Answer</summary>

**B**: It happens when the pivot is always the smallest or largest element, for example a sorted array with the first element as pivot. The average is O(n log n).

</details>

**54. Which sorting algorithm is stable?**

- (A) Heap sort
- (B) Selection sort
- (C) Quick sort
- (D) Merge sort

<details><summary>Answer</summary>

**D**: Stable means equal keys keep their original order. Insertion sort and bubble sort are also stable.

</details>

**55. Hash table lookup takes on average and in the worst case:**

- (A) O(1) and O(1)
- (B) O(log n) and O(n)
- (C) O(n) and O(n)
- (D) O(1) on average, O(n) in the worst case

<details><summary>Answer</summary>

**D**: The worst case happens when every key collides into the same bucket.

</details>

**56. Which data structure does BFS use?**

- (A) Heap
- (B) Hash set only
- (C) Stack
- (D) Queue

<details><summary>Answer</summary>

**D**: DFS uses a stack (or recursion). Dijkstra uses a priority queue.

</details>

**57. An inorder traversal of a binary search tree visits the keys:**

- (A) In reverse sorted order
- (B) In level order
- (C) In insertion order
- (D) In sorted (ascending) order

<details><summary>Answer</summary>

**D**: This is the standard way to check whether a tree is a valid BST.

</details>

**58. Dijkstra's algorithm may give wrong answers when the graph has:**

- (A) Negative edge weights
- (B) More than 10^5 vertices
- (C) Undirected edges
- (D) Cycles

<details><summary>Answer</summary>

**A**: Use Bellman-Ford when there are negative edges. Bellman-Ford can also detect negative cycles.

</details>

**59. What does T(n) = 2T(n/2) + n solve to?**

- (A) O(n log n)
- (B) O(n)
- (C) O(log n)
- (D) O(n^2)

<details><summary>Answer</summary>

**A**: This is case 2 of the Master theorem, and it is the merge sort recurrence.

</details>

**60. Building a binary heap from n unsorted elements with bottom-up heapify takes:**

- (A) O(n log n)
- (B) O(log n)
- (C) O(n)
- (D) O(n^2)

<details><summary>Answer</summary>

**C**: Most nodes are near the bottom and sift down only a short distance, so the total work is linear.

</details>

**61. What is the minimum number of edges in a connected undirected graph with n vertices?**

- (A) n − 1
- (B) n(n−1)/2
- (C) n
- (D) log n

<details><summary>Answer</summary>

**A**: Such a graph is a tree. Adding one more edge creates a cycle.

</details>

**62. for (i = 1..n) { for (j = 1; j < n; j *= 2) {...} } has complexity:**

- (A) O(n)
- (B) O(n log n)
- (C) O(n^2)
- (D) O(log^2 n)

<details><summary>Answer</summary>

**B**: The inner loop doubles j each time, so it runs log n times for each of the n outer iterations.

</details>

**63. What does the postfix expression 2 3 4 * + evaluate to?**

- (A) 24
- (B) 10
- (C) 14
- (D) 20

<details><summary>Answer</summary>

**C**: Use a stack: 3 × 4 = 12, then 2 + 12 = 14.

</details>

**64. Which combination gives an LRU cache with O(1) get and put?**

- (A) Singly linked list only
- (B) Hash map + doubly linked list
- (C) Array + binary search
- (D) Min-heap only

<details><summary>Answer</summary>

**B**: The map finds the node in O(1). The list moves the node to the front, or removes the oldest from the back, in O(1).

</details>

**65. How many structurally different BSTs can be built from 3 distinct keys?**

- (A) 3
- (B) 6
- (C) 8
- (D) 5

<details><summary>Answer</summary>

**D**: This is the Catalan number C3 = 5.

</details>

**66. Which data structure is best for autocomplete (prefix search)?**

- (A) Hash set of full words
- (B) Trie
- (C) Queue
- (D) Heap

<details><summary>Answer</summary>

**B**: Searching a prefix of length L takes O(L), and all words with that prefix are below that node.

</details>

**67. Which algorithm detects a cycle in a DIRECTED graph?**

- (A) Plain BFS with a visited set
- (B) DFS that tracks nodes on the current recursion stack (or Kahn's algorithm failing to process all nodes)
- (C) Binary search
- (D) Union-Find on the directed edges

<details><summary>Answer</summary>

**B**: Union-Find works for undirected graphs but not directed ones. A visited node reached again in BFS is not always a cycle in a directed graph.

</details>

**68. You need the minimum capacity that lets a task finish within D days, and the check "does capacity X work?" is monotonic. Which technique fits best?**

- (A) Binary search on the answer
- (B) Backtracking
- (C) Topological sort
- (D) Sliding window

<details><summary>Answer</summary>

**A**: Search over the range of possible answers. Each check is usually an O(n) greedy pass.

</details>

**69. What is the height of a complete binary tree with n nodes?**

- (A) √n
- (B) ⌊log2 n⌋
- (C) n / 2
- (D) n − 1

<details><summary>Answer</summary>

**B**: Each level doubles the number of nodes, so the height is logarithmic.

</details>

---

## Cloud & DevOps

**70. Which is an example of SaaS?**

- (A) Amazon EC2
- (B) Gmail / Microsoft 365
- (C) A bare-metal server rental
- (D) Google App Engine

<details><summary>Answer</summary>

**B**: IaaS gives you VMs (EC2). PaaS gives you a platform to deploy code (App Engine, Heroku). SaaS is finished software.

</details>

**71. The key difference between containers and virtual machines is:**

- (A) VMs start faster than containers
- (B) Containers cannot run on Linux
- (C) Containers share the host OS kernel. VMs each run a full guest OS on a hypervisor.
- (D) Containers need a hypervisor

<details><summary>Answer</summary>

**C**: Because they share the kernel, containers are lighter and start faster, but they are less isolated.

</details>

**72. What is the smallest deployable unit in Kubernetes?**

- (A) Container image
- (B) Deployment
- (C) Pod
- (D) Node

<details><summary>Answer</summary>

**C**: A pod holds one or more containers that share network and storage. A Deployment manages ReplicaSets of pods.

</details>

**73. Horizontal scaling means:**

- (A) Adding more CPU/RAM to one machine
- (B) Adding more machines or instances
- (C) Compressing the data
- (D) Moving to a faster disk

<details><summary>Answer</summary>

**B**: Vertical scaling (scale up) means making one machine bigger.

</details>

**74. How are serverless functions (such as AWS Lambda) usually billed?**

- (A) Per line of code
- (B) Per number of developers
- (C) A fixed monthly price per server
- (D) Per invocation and execution time

<details><summary>Answer</summary>

**D**: Serverless functions scale to zero when idle. The trade-offs are cold starts and execution time limits.

</details>

**75. The CAP theorem says that during a network partition, a distributed system must choose between:**

- (A) Security and Scalability
- (B) Cost and Performance
- (C) Consistency and Availability
- (D) Availability and Durability

<details><summary>Answer</summary>

**C**: Partitions cannot be avoided, so the real choice is between CP and AP.

</details>

**76. Continuous Integration (CI) means:**

- (A) Developers merge often, and every merge is automatically built and tested
- (B) Code is deployed to production by hand once a month
- (C) Only the QA team runs tests
- (D) Deploying without version control

<details><summary>Answer</summary>

**A**: Continuous Delivery and Deployment extend CI by automatically releasing the build.

</details>

**77. Which AWS service is object storage?**

- (A) Amazon EC2
- (B) AWS Lambda
- (C) Amazon S3
- (D) Amazon RDS

<details><summary>Answer</summary>

**C**: In Azure this is Blob Storage, and in GCP it is Cloud Storage. RDS is managed relational databases.

</details>

**78. Deploying across multiple Availability Zones mainly improves:**

- (A) Compile speed
- (B) Code readability
- (C) Per-request latency within a single zone
- (D) High availability and fault tolerance

<details><summary>Answer</summary>

**D**: If one data centre fails, the others keep serving traffic.

</details>

**79. Under the cloud shared-responsibility model, for IaaS the CUSTOMER is responsible for:**

- (A) The hypervisor
- (B) Their data, IAM permissions, OS patching and application security
- (C) Power and cooling
- (D) The physical security of data centres

<details><summary>Answer</summary>

**B**: The provider secures the cloud itself. The customer secures what they put in it.

</details>

**80. A CDN reduces latency mainly by:**

- (A) Compressing the database
- (B) Caching content on edge servers close to users
- (C) Increasing CPU clock speed
- (D) Encrypting traffic

<details><summary>Answer</summary>

**B**: Examples include CloudFront, Akamai and Cloudflare.

</details>

**81. In Docker, the relationship between an image and a container is:**

- (A) A container is a running instance of an image
- (B) An image is a running container
- (C) They are the same thing
- (D) A container builds the Dockerfile

<details><summary>Answer</summary>

**A**: A Dockerfile builds an image, an image is run as a container, and the same image can run as many containers.

</details>

**82. A load balancer is mainly used to:**

- (A) Store session data permanently
- (B) Back up the database
- (C) Compile code
- (D) Spread incoming traffic across several servers

<details><summary>Answer</summary>

**D**: It also runs health checks and removes unhealthy instances from rotation.

</details>

---

## Security

**83. Which of these is a symmetric encryption algorithm?**

- (A) RSA
- (B) AES
- (C) ECC
- (D) Diffie-Hellman

<details><summary>Answer</summary>

**B**: RSA and ECC are asymmetric. Diffie-Hellman is a key-exchange protocol.

</details>

**84. How does hashing differ from encryption?**

- (A) Encryption is always one-way
- (B) Hashing needs a key to reverse
- (C) Hashing is one-way. Encryption can be reversed with a key.
- (D) They are the same

<details><summary>Answer</summary>

**C**: Hashes are used for integrity checks and storing passwords. Encryption is used for confidentiality.

</details>

**85. What is the best way to store user passwords?**

- (A) An unsalted MD5 hash
- (B) Plain text in a protected table
- (C) A salted, slow hash such as bcrypt or Argon2
- (D) AES encryption with a key stored in the code

<details><summary>Answer</summary>

**C**: The salt defeats rainbow tables, and the slow hash makes brute force expensive.

</details>

**86. What is the most effective defence against SQL injection?**

- (A) Using HTTPS
- (B) Parameterized queries (prepared statements)
- (C) Hiding error messages
- (D) Client-side input validation only

<details><summary>Answer</summary>

**B**: With parameters, user input is treated as data and never as SQL code.

</details>

**87. To create a digital signature, the sender signs with:**

- (A) A shared symmetric key
- (B) The sender's public key
- (C) The sender's private key
- (D) The receiver's public key

<details><summary>Answer</summary>

**C**: Anyone can verify the signature with the sender's public key. This gives authenticity and non-repudiation.

</details>

**88. Cross-Site Scripting (XSS) is:**

- (A) Flooding a server with traffic
- (B) Forging requests from a logged-in user's browser
- (C) Guessing passwords
- (D) Injecting malicious scripts into pages that other users view

<details><summary>Answer</summary>

**D**: The first wrong option describes CSRF and the second describes DoS. Defend against XSS with output encoding and a Content Security Policy.

</details>

---

## Web, AI & Software Engineering

**89. How does React's virtual DOM improve performance?**

- (A) It compares the new virtual tree with the old one and applies only the minimum changes to the real DOM
- (B) It caches API responses
- (C) It runs JavaScript on the server only
- (D) It replaces the browser's DOM completely

<details><summary>Answer</summary>

**A**: This comparison step is called reconciliation.

</details>

**90. In React, when does useEffect(fn, []) run fn (outside StrictMode development)?**

- (A) Before every render
- (B) Never
- (C) Once, after the first render (on mount)
- (D) After every render

<details><summary>Answer</summary>

**C**: With no dependency array, it runs after every render. With [x], it runs whenever x changes.

</details>

**91. A model with 99% training accuracy and 70% test accuracy is most likely:**

- (A) Underfitting
- (B) Perfectly generalised
- (C) Suffering from data leakage only
- (D) Overfitting

<details><summary>Answer</summary>

**D**: Remedies include more data, regularisation, dropout, early stopping and simpler models.

</details>

**92. Precision is defined as:**

- (A) (TP + TN) / total
- (B) TP / (TP + FP)
- (C) TN / (TN + FP)
- (D) TP / (TP + FN)

<details><summary>Answer</summary>

**B**: TP / (TP + FN) is recall. Precision asks how many of the predicted positives are correct. Recall asks how many of the real positives were found.

</details>

**93. Retrieval-Augmented Generation (RAG) mainly helps an LLM by:**

- (A) Making the model smaller
- (B) Removing the need for prompts
- (C) Grounding its answers in relevant documents retrieved at query time
- (D) Training the model from scratch on company data

<details><summary>Answer</summary>

**C**: RAG lowers hallucination on company-specific questions without retraining the model. This is a common GenAI consulting use case.

</details>

**94. Which is an example of supervised learning?**

- (A) Reducing dimensions with PCA
- (B) Classifying emails as spam using emails that already have labels
- (C) An agent learning by trial and error from rewards
- (D) Grouping customers into segments without labels

<details><summary>Answer</summary>

**B**: The wrong options are clustering (unsupervised), dimensionality reduction (unsupervised) and reinforcement learning.

</details>

**95. The main advantage of microservices over a monolith is:**

- (A) Each service can be deployed and scaled on its own
- (B) No need for APIs
- (C) Simpler debugging and no network calls
- (D) Always lower infrastructure cost

<details><summary>Answer</summary>

**A**: The trade-offs are more complex operations, network latency and distributed data consistency.

</details>

**96. Agile/Scrum delivers software:**

- (A) Without any customer involvement
- (B) Only after all requirements are fixed up front
- (C) Iteratively, in short sprints, with regular feedback
- (D) In one big release at the end

<details><summary>Answer</summary>

**C**: Delivering only after all requirements are fixed up front describes the Waterfall model.

</details>

**97. What does `git rebase` do that `git merge` does not?**

- (A) It rewrites history by replaying commits on top of another base
- (B) It deletes the branch
- (C) It creates a merge commit
- (D) It pushes to the remote

<details><summary>Answer</summary>

**A**: Never rebase commits that other people have already pulled. Use merge on shared branches.

</details>

**98. An LLM "hallucination" is:**

- (A) An out-of-memory error
- (B) Fluent, confident output that is factually wrong or made up
- (C) A slow response
- (D) The model refusing to answer

<details><summary>Answer</summary>

**B**: Ways to reduce it include RAG, citations, lower temperature, human review and evaluation sets.

</details>
