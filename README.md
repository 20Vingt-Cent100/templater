# Templater

## Introduction
Templater is a tool to simplify project initialization and reduce the amount of boilerplate needed. It allows, to copy templates via a single command.

Every template is defined with a .template file

## Roadmap & TODO
1. Core Engine

   [ ] Template Structuring: Establish basic folder structuring via template definitions.

   [ ] File Generation: Implement basic file copying for projects using a template with predefined files.

   [ ] Template Configuration: Add YAML parsing for template definitions.

2. Templating & CLI Enhancements

   [ ] Variable Substitution: Support inline variables using the $ character.

   [ ] Code Architecture: Refactor and implement a dedicated templateGenerator type.

   [ ] CLI Usability: Build better argument parsing for smoother command-line execution.

3. Advanced Features

   [ ] Lifecycle Hooks: Support pre-init and post-init hooks (such as installation scripts, etc.).

   [ ] Remote Sources: Add support for remote template sources/types (such as GitHub repositories via HTTPS/SSH).

## Using Templater
