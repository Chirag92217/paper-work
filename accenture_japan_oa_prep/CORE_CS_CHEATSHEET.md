# Core CS Cheat Sheet: Last-48-Hours Revision

These are short notes for MCQ revision. If any line feels unfamiliar, go back and study that topic properly.

## Operating Systems

| Concept | Remember |
|---|---|
| Process vs thread | A process has its own address space. Threads share code, heap and globals, but each has its own **stack, registers and PC**. A thread switch is cheaper because there is no address-space/TLB switch. |
| Scheduling | FCFS (convoy effect) · SJF (lowest average waiting time, but can starve long jobs) · SRTF = preemptive SJF · RR (time quantum; a huge quantum makes it FCFS) · Priority (starvation, fixed by **aging**) |
| Formulas | Turnaround = Completion − Arrival · Waiting = Turnaround − Burst · Response = First run − Arrival |
| Deadlock (Coffman) | Mutual exclusion + Hold & wait + **No preemption** + Circular wait. Prevention = break one condition. Avoidance = **Banker's** (safe state). Detection = wait-for graph. |
| Sync | Critical section needs mutual exclusion + progress + bounded waiting. Mutex = lock with an owner. Semaphore = counter (wait/P decrements, signal/V increments). Classic problems: producer-consumer, readers-writers, dining philosophers. |
| Memory | Paging → internal fragmentation, no external. Segmentation → external fragmentation. Offset bits = log2(page size). Number of pages = 2^(VA bits − offset bits). TLB = cache for the page table. |
| Page replacement | FIFO (**Belady's anomaly**) · LRU · Optimal (lowest faults, needs the future; used as a benchmark). LRU and Optimal are stack algorithms, so they have no Belady's anomaly. |
| Misc | Thrashing = too much paging. Zombie = finished but parent hasn't called wait(). Orphan = parent died first. `fork()` n times → 2^n processes. |

## Computer Networks

| Concept | Remember |
|---|---|
| OSI (7) | Physical, Data link (MAC, switch), Network (IP, router), Transport (TCP/UDP, ports), Session, Presentation (encryption/format), Application |
| TCP vs UDP | TCP: connection-oriented, reliable, ordered, flow control (receiver window) and congestion control (slow start, cwnd). UDP: connectionless, fast. Used for DNS, streaming and games. |
| Handshakes | Open: SYN → SYN-ACK → ACK. Close: FIN/ACK four-way. |
| Ports | 20/21 FTP · 22 SSH · 23 Telnet · 25 SMTP · 53 DNS · 67/68 DHCP · 80 HTTP · 110 POP3 · 143 IMAP · 443 HTTPS · 3306 MySQL · 5432 Postgres |
| Protocols | ARP: IP → MAC · DNS: name → IP · DHCP: hands out IPs · ICMP: ping/traceroute · NAT: private ↔ public |
| Addressing | IPv4 = 32 bits, IPv6 = 128 bits. Usable hosts in a /n subnet = 2^(32−n) − 2. Private ranges: 10/8, 172.16/12, 192.168/16. |
| HTTP | GET (safe, idempotent) · PUT/DELETE (idempotent) · POST (not idempotent) · 200 OK, 201 Created, 204 No Content, 301/302 redirect, 304 Not Modified, 400 Bad Request, **401 not authenticated**, **403 not allowed**, 404, 429 rate limit, 500, 502 bad gateway, 503 unavailable |
| REST | Stateless, client-server, cacheable, uniform interface (resources + HTTP verbs), layered |
| What happens when you type a URL | DNS → TCP handshake → TLS handshake → HTTP request → server/LB → response → browser renders |

## DBMS & SQL

| Concept | Remember |
|---|---|
| ACID | Atomicity (all or nothing) · Consistency (constraints hold) · Isolation (no seeing uncommitted work) · Durability (survives crashes, via the WAL) |
| Isolation anomalies | Dirty read → prevented by Read Committed · Non-repeatable read → Repeatable Read · Phantom → Serializable |
| Normal forms | 1NF atomic values · 2NF no partial dependency · 3NF no transitive dependency · BCNF: every determinant is a superkey |
| Keys | Super ⊇ Candidate (minimal) → Primary (one chosen; unique + not null). Foreign key refers to another table's key. |
| Joins | INNER (matches only) · LEFT/RIGHT (all rows from one side + NULLs) · FULL · CROSS (m × n rows) · SELF |
| Clauses | Order of execution: FROM → WHERE → GROUP BY → HAVING → SELECT → ORDER BY → LIMIT. WHERE filters rows; HAVING filters groups. |
| DDL vs DML | DELETE (rows, can roll back) · TRUNCATE (all rows, fast) · DROP (table + structure) |
| Indexes | B+ tree. Faster reads, slower writes. One clustered index per table, many non-clustered. |
| NULL | `COUNT(col)` skips NULLs. `NULL = NULL` is unknown, so use `IS NULL`. |

```sql
-- Nth highest salary
SELECT DISTINCT salary FROM emp ORDER BY salary DESC LIMIT 1 OFFSET N-1;
-- Departments with more than 5 employees
SELECT dept, COUNT(*) FROM emp GROUP BY dept HAVING COUNT(*) > 5;
-- Employees earning more than their manager (self join)
SELECT e.name FROM emp e JOIN emp m ON e.manager_id = m.id WHERE e.salary > m.salary;
```

## OOP

- **Four pillars:** encapsulation (data + methods, access control) · abstraction (show only what is essential) · inheritance (is-a) · polymorphism.
- **Overloading** = same name, different parameters, chosen at **compile time**. **Overriding** = subclass redefines a method, chosen at **runtime** (virtual/vtable).
- **C++:** virtual destructor in base classes · pure virtual (`=0`) → abstract class · diamond problem → `virtual` inheritance · constructors cannot be virtual.
- **Java:** abstract class (state + constructors, single inheritance) vs interface (no instance state, multiple allowed, default methods since Java 8).
- **SOLID:** Single responsibility · Open/closed · Liskov substitution · Interface segregation · Dependency inversion.
- **Patterns to recognise:** Singleton, Factory, Observer (pub/sub), Strategy, Adapter, Decorator, MVC.

## DSA Complexity Table

| Operation | Complexity |
|---|---|
| Binary search | O(log n) |
| Merge sort | O(n log n), stable, O(n) extra space |
| Quick sort | O(n log n) average, **O(n²) worst**, not stable |
| Heap sort | O(n log n), not stable · building a heap is **O(n)** |
| Counting sort | O(n + k) |
| Hash map | O(1) average / O(n) worst |
| Balanced BST / `set` / `map` | O(log n) |
| Heap push/pop | O(log n), peek O(1) |
| BFS / DFS | O(V + E) |
| Dijkstra (heap) | O((V + E) log V), **no negative edges** |
| Bellman-Ford | O(VE), handles negative edges, detects negative cycles |
| Floyd-Warshall | O(V³), all pairs |
| Kruskal / Prim | O(E log E) / O(E log V) |
| Topological sort | O(V + E), DAG only |

Master theorem cases to remember: `T(n)=2T(n/2)+n → n log n`, `T(n)=T(n/2)+1 → log n`, `T(n)=2T(n/2)+1 → n`, `T(n)=T(n−1)+n → n²`.

## Cloud, DevOps & Modern Tech

- **IaaS** (EC2, Azure VMs) → **PaaS** (App Engine, Elastic Beanstalk, Heroku) → **SaaS** (Gmail, Salesforce). As you go right, you manage less.
- **Deployment models:** public, private, hybrid, multi-cloud.
- **Key AWS services:** EC2 (compute) · S3 (object storage) · RDS (managed SQL) · DynamoDB (NoSQL) · Lambda (serverless) · VPC (network) · IAM (identity) · CloudFront (CDN) · ELB (load balancer). Azure/GCP equivalents: Blob/Cloud Storage, Azure Functions/Cloud Functions.
- **Containers vs VMs:** containers share the host kernel (light, fast); VMs run a full guest OS (stronger isolation). Docker: Dockerfile → image → container.
- **Kubernetes:** Pod (smallest unit) · Node · Cluster · Deployment (desired replicas, rolling updates) · Service (stable network endpoint) · Ingress · auto-scaling (HPA).
- **Scaling:** vertical (bigger machine) vs horizontal (more machines + load balancer). Stateless services scale horizontally.
- **Reliability:** multi-AZ / multi-region, CDN, caching (Redis), message queues (SQS, Kafka) to decouple services.
- **CAP:** during a network partition, choose Consistency or Availability.
- **CI/CD:** automated build → test → deploy pipeline (GitHub Actions, Jenkins). Infrastructure as Code: Terraform, CloudFormation.
- **Security basics:** symmetric (AES) vs asymmetric (RSA/ECC) · hashing is one-way (SHA-256) · passwords: bcrypt/Argon2 + salt · sign with your private key · SQL injection → parameterised queries · XSS → output encoding · CSRF → tokens / SameSite cookies.
- **AI/GenAI:** supervised / unsupervised / reinforcement learning · overfitting (train ≫ test) · precision = TP/(TP+FP), recall = TP/(TP+FN) · LLM, prompt, token, context window · **RAG** (retrieve documents, then generate; reduces hallucination) · fine-tuning vs RAG · risks: hallucination, privacy, bias, cost.
