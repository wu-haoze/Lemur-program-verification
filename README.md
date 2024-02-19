# Lemur

This repo contains the source code for the paper [Lemur: Integrating Large Language Models in Automated Program Verification](https://arxiv.org/abs/2310.04870)

## Requirements

The implementation is tested on **python3.8.10**, 
but should work on more recent python versions.

### Python packages
The Python package dependencies can be installed by

``pip install -r requirements.txt``

### OpenAI API

You also need a working OPEN API key, and set the environment variable OPENAI_API_KEY.

``export OPENAI_API_KEY=YOUR_KEY``

### Solvers

You need to download two software verification tools by running

``./build.sh``

## Experiments

There are two experiments that we performed. The source code as well as the log files for each are contained in "code2inv/" and "lemur/", respectively.

## Citation
```
@inproceedings{wu2023lemur,
  title={Lemur: Integrating Large Language Models in Automated Program Verification},
  author={Wu, Haoze and Barrett, Clark and Narodytska, Nina},
  booktitle={The Twelfth International Conference on Learning Representations},
  year={2024}
}
```
