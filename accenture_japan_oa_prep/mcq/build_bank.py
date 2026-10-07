"""Generate MCQ_BANK.md from questions.json (options shuffled with a fixed seed, answers in collapsible blocks)."""
import json
import random
from collections import Counter
from pathlib import Path

here = Path(__file__).parent
qs = json.loads((here / "questions.json").read_text())
rng = random.Random(7)

counts = Counter(q["t"] for q in qs)
out = [
    "# MCQ Practice Bank",
    "",
    f"{len(qs)} questions on the topics reported in past Accenture Japan OAs: OS, CN, DBMS, OOP, DSA, Cloud, Security, Web/AI.",
    "Cover the answers, attempt a full section, then check. Aim for **≥ 85%** before the OA. In past reports, MCQ accuracy mattered a lot for shortlisting.",
    "",
    "| Topic | Questions |",
    "|---|---|",
]
out += [f"| {t} | {n} |" for t, n in counts.items()]
out.append("")

topic, num = None, 0
for q in qs:
    if q["t"] != topic:
        topic = q["t"]
        out += ["---", "", f"## {topic}", ""]
    num += 1
    opts = [q["a"]] + q["w"]
    rng.shuffle(opts)
    letter = "ABCD"[opts.index(q["a"])]
    out.append(f"**{num}. {q['q']}**")
    out.append("")
    out += [f"- ({'ABCD'[i]}) {o}" for i, o in enumerate(opts)]
    out += ["", f"<details><summary>Answer</summary>", "", f"**{letter}**: {q['e']}", "", "</details>", ""]

(here / "MCQ_BANK.md").write_text("\n".join(out))
print(f"wrote {num} questions")

# Inject the same questions into the interactive mock test page.
template = (here / "mock_test.template.html").read_text()
compact = json.dumps(qs, ensure_ascii=False, separators=(",", ":")).replace("</", "<\\/")
(here / "mock_test.html").write_text(template.replace("/*QUESTIONS*/[]", compact))
print("wrote mock_test.html")
