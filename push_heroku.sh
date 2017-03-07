#!/bin/bash
set -e -u

git subtree push --prefix server heroku master
