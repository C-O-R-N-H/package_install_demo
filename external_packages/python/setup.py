from setuptools import setup

setup(
    name='math_pkg',
    version='0.1',
    description='A simple Python package',
    author='WP',
    author_email='WP@example.com',
    packages=['math_pkg'],
    install_requires=[
        'numpy',
        'pandas',
    ],
)