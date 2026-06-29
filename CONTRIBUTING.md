# Contributing to MinGLE

Thank you for your interest in improving **MinGLE (Mini Geant4 Learning Example)**! As an open-source project designed to make learning Geant4 more accessible, community contributions, bug reports, and pedagogical improvements are highly welcome.

Since MinGLE is currently maintained by a single lead developer, following these guidelines helps streamline the review process and ensures the project remains clean, minimalist, and functional.

---

## Code Governance & Scope

MinGLE has a very specific architectural constraint: **the core `mingle.cc` file on any branch must remain as close to a minimalist baseline (~70 lines of code) as possible.**
* **Pedagogical Integrity:** Extensions or feature requests that add extensive boilerplate or highly specialized experiment geometries will generally be declined or requested to be moved to external macros.
* **The "Branch-as-Chapter" Rule:** Updates or bug fixes must be target-specific. If you fix a bug related to particle generation, the fix may need to propagate through tags `v6` to `v9`. Please coordinate via an Issue before opening complex multi-branch Pull Requests.

---

## How Can I Contribute?

### 1. Reporting Bugs & Issues
If you encounter compilation errors, broken dependencies with newer Geant4 releases, or logical bugs in the macro scripts:
1. Search the [GitHub Issues](https://github.com/jintonic/mingle/issues) to ensure it hasn't already been reported.
2. If it is new, open an Issue using a clear title.
3. Provide your environment details: Operating System, CMake version, and your specific **Geant4 installation version**.
4. Include the exact terminal output or compiler error logs.

### 2. Suggesting Pedagogical Improvements
MinGLE is an educational tool. If you find a comment confusing, a `README.md` file in a specific branch unclear, or feel a step in the learning sequence skips essential logic:
* Open an issue outlining the pedagogical gap.
* We highly welcome updates that clarify documentation or improve the onboarding experience for students!

### 3. Submitting Pull Requests (PRs)
For small fixes, documentation updates, or standard CMake patches:
1. Fork the repository and create a feature branch off of the target branch (e.g., `fix/gps-macro-syntax` off of the `gps` branch).
2. Ensure your code strictly adheres to modern Geant4 standards (using factory classes and keeping formatting uniform).
3. Verify that your modified code compiles successfully against a standard Geant4 environment.
4. Submit your Pull Request with a clear description of the problem it solves.

---

## Support & Expectation Management

MinGLE is a single-maintainer project integrated into active university research and onboarding pipelines. 
* **Review Timelines:** While issues and PRs are monitored closely, please allow a few business days for code reviews and discussion. 
* **Community Standards:** We expect all contributors to maintain a professional, encouraging, and supportive tone. This project is built specifically to lift beginners up into functional application developers!