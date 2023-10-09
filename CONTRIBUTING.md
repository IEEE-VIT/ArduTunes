# Contributing Guidelines

This document contains certain rules and guidelines that developers are expected to follow, while contributing to any repository.

---

## 1. Commit Messages

- Use the `-m` flag only for minor changes. The message following the `-m` flag must be of the below format :

  > `<Verb in present tense> <Action>`

  :white_check_mark: **Examples of valid messages:**

  - Added pitch.h to the project
  - Updated mainVolume.ino file
  - Changed visual of the DIY Synthesizer

  :x: **Examples of invalid messages:**

  - Idk why this is not working
  - Only some bug fixes left
  - All changes done, ready for playing :))

- Before opening a PR, make sure you squash all your commits into one single commit using `git rebase` (squash). Instead of having 50 commits that describe 1 feature implementation, there must be one commit that describes everything that has been done so far. You can read up about it [here](https://www.internalpointers.com/post/squash-commits-into-one-git).
  > NOTE: While squashing your commits to write a new one, do not make use of `-m` flag. In this case, a vim editor window shall open. Write a title for the commit within 50-70 characters, leave a line and add an understandable description.

## 2. Issues

- Issues **MUST** be opened any time any of the following events occur :
  1. You encounter an issue such that a major (50 lines of code or above) portion of the code needs to be changed/added.
  2. You want feature enhancements
  3. You encounter bugs
  4. Code refactoring is required
  5. Test coverage should be increased
- **Open issues with the given template only.**
- Feel free to label the issues appropriately.
- Do not remove the headings (questions in bold) while opening an issue with the given template. Simply append to it.

## 3. Branches and PRs

- No commits must be made to the `main` branch directly. The `main` branch shall only consist of the working code.
- Developers are expected to work on feature branches, and upon successful development and testing, a PR (pull request) must be opened to merge with main.
- A branch must be named as either as the feature being implemented, or the issue being fixed.

  :white_check_mark: **Examples of valid brach names:**

  - #8123 (issue number)
  - MasterVolume (feature)
  - pitchArduTunes (functionality of the questions)

  :x: **Examples of invalid branch names**:

  - ziyan-testing
  - attemptToFixAuth
  - SomethingRandom

## 4. Discussion Ethics

- Developers should be clear and concise while commenting on issues or PR reviews. If needed, one should provide visual reference or a code snippet for everyone involved to properly grasp the issue.
- Everyone should be respectful of everyone's opinion. Any harsh/disrespectful language is **STRICTLY** prohibited and will not be tolerated under any circumstances.

## 5. Coding Ethics

- Developers are highly encouraged to use comments wherever necessary and make the code self documented.
- The project structure should be neat and organised. All folders and files should be organised semantically according to their functionality.
- The name of the folders and files should not be too long but should be as self explanatory as possible.
- Documentation shall **STRICTLY** have gender neutral terms. Instead of using "he/him" or "she/her", one should use "they/them" or "the user".

## 6. Coding Style Guidelines

Developers should aim to write clean, maintainable, scalable and testable code. If your code is not testable, that means, it's time to refactor it. The following guidelines might come in handy for this:

- C++: [Cpp Core Guideline](https://github.com/isocpp/CppCoreGuidelines)
- Wokwi: [Wokwi Guide](https://blog.wokwi.com/how-to-write-clean-arduino-code/)
- Commit messages: [Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/)
