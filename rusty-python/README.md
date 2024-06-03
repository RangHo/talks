# Rusty Python
여기에는 제 블로그 글 [Rusty Python](https://rangho.postype.com/post/6680526)에서 퍼포먼스 배틀을 진행할 때 사용한 코드를 담고 있습니다. 각 모듈마다 사용 방법이 다르므로 아래를 참고하여 모듈을 컴파일한 뒤 사용해 주세요.

## `pythonsieve`: 파이썬 에라토스테네스의 체 구현체
이 모듈은 딱히 컴파일할 필요가 없습니다. 그냥 이 리포지토리 디렉터리에서 pythonsieve 모듈을 임포트하실 수 있어요. 따로 `setup.py` 파일은 제공하지 않습니다.

``` python
import pythonsieve

pythonsieve.sieve(100)
```

## `csieve`: C언어 에라토스테네스의 체 구현체
이 모듈은 파이썬 `distutils` 모듈을 이용하여 컴파일합니다. `csieve` 디렉터리에 들어간 후 다음 명령어를 입력하세요.
``` shell
python setup.py install
```

이를 이용하면 시스템 전체에 해당 모듈이 등록되므로 `virtualenv` 환경 안에서 설치하는 것을 권장합니다.

``` python
import csieve

csieve.sieve(100)
```

## `rustsieve`: Rust 에라토스테네스의 체 구현체
이 모듈은 PyO3 라이브러리에서 제공하는 `maturin` 빌드 시스템을 사용합니다. PIP 저장소에서 다운받을 수 있고, 이미 `requirements.txt` 파일에 필요한 패키지가 들어 있으니 다음 명령어를 이용하여 설치하세요. 미리 `rustsieve` 디렉터리로 `cd`하는 것도 잊지 마시고요!
``` shell
pip install -r requirements.txt
maturin develop --release
```
마찬가지로 전역 PIP 저장소에 등록되는 것이 싫다면 미리 `virtualenv` 환경 안에서 작업하는 것을 추천드립니다.

``` python
import rustsieve

rustsieve.sieve(100)
```
