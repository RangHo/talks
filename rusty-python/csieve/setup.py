from distutils.core import Extension
from distutils.core import setup


def main():
    setup(
        name="csieve",
        version="1.0.0",
        description="Sieve of Eratosthenes in C",
        author="RangHo Lee",
        author_email="hello@rangho.me",
        ext_modules=[Extension("csieve", ["csieve.c"])]
    )


if __name__ == "__main__":
    main()
