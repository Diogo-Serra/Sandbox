PY := /usr/bin/env python3
ENV_PY := .venv/bin/python3
ENV_PIP := .venv/bin/pip
ENV := .venv/bin/

WIDTH := 10
HEIGHT := 10

install:
	$(PY) -m venv .venv
	$(ENV_PIP) install -r requirements.txt

run:
	$(PY) nav.py $(WIDTH) $(HEIGHT)

clean:
	rm -rf .venv
	rm -rf $$(find . -name __pycache__ -o -name .mypy_cache)

lint:
	$(ENV)flake8 . --exclude=.venv
	$(ENV)mypy . --strict
