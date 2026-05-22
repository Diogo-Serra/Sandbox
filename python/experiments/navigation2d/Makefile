PY := /usr/bin/env python3

ENV := .venv/bin/
ENV_PIP := $(ENV)pip
ENV_PY := $(ENV)python3

WIDTH := 10
HEIGHT := 10


install:
	$(PY) -m venv .venv
	$(ENV_PIP) install -r src/requirements.txt

run:
	$(ENV_PY) nav.py $(WIDTH) $(HEIGHT)

clean:
	rm -rf .venv
	rm -rf $$(find . -name __pycache__ -o -name .mypy_cache)

lint:
	$(ENV)flake8 . --exclude=.venv
	$(ENV)mypy . --strict
