SHELL := /bin/bash

PY := python3
ENV := -m venv .venv
CLEAN_ENV := rm -rf .venv
PIP := pip install -r requirements.txt
ACTIVATE_ENV := source .venv/bin/activate


install:
	$(PY) $(ENV) && $(ACTIVATE_ENV) && $(PIP)

run:
	$(ACTIVATE_ENV) && $(PY) main.py config.txt --viz

clean:
	$(CLEAN_ENV)