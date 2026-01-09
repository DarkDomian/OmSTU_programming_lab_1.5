# =============================================================================
# Main Config and Targets
# =============================================================================
CC				::=		gcc
CFLAGS			::=		-Wall -Werror -Wextra -std=c11 -pedantic -g -lm

SOURCES			::=		$(wildcard src/task-*.c)
TASKS			::=		task-1 task-2 task-3 task-4 task-5 task-6

.PHONY: all style_format style_check clean rebuild {TASKS}

all: ${TASKS}

task-%: src/task-%.c
	$(info Building the $@ object file...)
	@$(CC) $(CFLAGS) $< -o $@
	@chmod +x $@

# =============================================================================
# Code Quality Rules
# =============================================================================
style_format:
	$(info Formatting code with clang-format...)
	@clang-format -i --verbose --style="{BasedOnStyle: Google}" ./*/*.[h,c]

style_check: $(SOURCES)
	$(info Checking style with clang-format and cppcheck...)
	@clang-format -n --style="{BasedOnStyle: Google}" --Werror ./*/*.[h,c]
	@cppcheck --enable=all --force --suppress=missingIncludeSystem --check-level=exhaustive --error-exitcode=1 $(SOURCES)
	@echo "Style check passed successfully!"

extra_style_format: $(SOURCES)
	$(info Formatting code with clang-tidy...)
	@clang-tidy ./*/*.[h,c] --fix -checks=-*,clang-analyzer-*,google-*,performance-*,portability-*,readability-* -- -Iinclude $(SOURCES)

extra_style_check: $(SOURCES)
	$(info Checking style with clang-tidy...)
	@clang-tidy ./*/*.[h,c] -header-filter=.* -checks=-*,clang-analyzer-*,google-*,performance-*,portability-*,readability-* -- -Iinclude $(SOURCES)

# =============================================================================
# Build Mode Rules
# =============================================================================
clean:
	$(info Cleaning the build artifacts...)
	@rm -rf ${TASKS}

rebuild: clean all
