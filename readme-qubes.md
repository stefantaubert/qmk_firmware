# dev on dev qube

## done steps initially

These steps were done after forking.

```sh
git clone git@github.com:stefantaubert/qmk_firmware.git
cd qmk_firmware
# https://docs.qmk.fm/#/newbs_git_using_your_master_branch
git remote add upstream https://github.com/qmk/qmk_firmware.git
# check
git remote -v
git checkout master
git fetch upstream
git pull upstream master
git push origin master
git checkout -b dev
git push --set-upstream origin dev
make git-submodule
python3.8 -m pip install pipenv --user
python3.8 -m pipenv install -r requirements.txt
python3.8 -m pipenv install --dev -r requirements-dev.txt
# check
pipenv run ./bin/qmk compile -kb ergodash/rev1 -km default
```

## setup

```sh
git clone git@github.com:stefantaubert/qmk_firmware.git
cd qmk_firmware
git checkout dev
make git-submodule
python3.8 -m pip install pipenv --user
python3.8 -m pipenv sync --dev
# check
pipenv run ./bin/qmk compile -kb ergodash/rev1 -km default
```

# firmware programming on other qube

## setup

```sh
git clone https://github.com/stefantaubert/qmk_firmware.git
cd qmk_firmware
git checkout dev
make git-submodule
python3.8 -m pip install pipenv --user
python3.8 -m pipenv sync
# check
pipenv run ./bin/qmk compile -kb ergodash/rev1 -km default
```

## prepare firmare stefan_v3

```sh
# creates or overwrites
cat > ./keyboards/ergodash/rev1/keymaps/stefan_v3/passwords.h << EOF
#define PWD1 ""
#define PWD2 ""
#define PWD3 ""
#define PWD4 ""
#define PWD5 ""
EOF
```

## update firmare stefan_v3

```sh
git pull; pipenv run ./bin/qmk compile -kb ergodash/rev1 -km stefan_v3
pipenv run ./bin/qmk flash -kb ergodash/rev1 -km stefan_v3
```
