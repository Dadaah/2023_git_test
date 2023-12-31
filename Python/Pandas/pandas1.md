# 판다스(Pandas) 소개
판다스는 파이썬 데이터 분석 라이브러리로 데이터 핸들링과 시각화를 위한 다양한 기능을 제공한다. 판다스는 시리즈(Series)와 데이터프레임(DataFrame) 자료형을 제공한다.  

## 판다스 설치
pip를 이용하여 판다스를 설치할 수 있다. 터미널에 다음 코드를 입력하면 판다스가 설치된다.
```bash
$ pip install pandas
```
  
판다스를 불러오기 위해서는 다음 코드를 사용하면 된다.
```python
import numpy as np
import pandas as pd
```

## 판다스의 기본 자료형
판다스는 데이터 핸들링을 위해 두 종료의 클래스를 제공한다.  
1. 시리즈(Series) : 일차원으로 레이블이 있는 배열이다. 어떤 타입의 데이터든 들어갈 수 있다.  
예) 정수형(interger), 문자열(strings) 등  

2. 데이터프레임(DataFrame) : 이차원 배열이나 행과 열이 있는 표처럼 데이터를 가지고 있는 이차원 데이터 구조다.

## 객체 생성
리스트를 사용해 시리즈를 만들 수 있다. 인덱스를 정하지 않으면 판다스가 기본 인덱스를 생성한다. 
```python
s = pd.Series([1, 3, 5, np.nan, 6, 8])
s
```
```
0    1.0
1    3.0
2    5.0
3    NaN
4    6.0
5    8.0
dtype: float64
```
딕셔너리를 사용해 데이터프레임을 만들 수 있다. 딕셔너리의 키가 열의 레이블이 되고, 값들이 열의 값이 된다.
```python
df2 = pd.DataFrame(
    {
        "A": 1.0,
        "B": pd.Timestamp("20130102"),
        "C": pd.Series(1, index=list(range(4)), dtype="float32"),
        "D": np.array([3] * 4, dtype="int32"),
        "E": pd.Categorical(["test", "train", "test", "train"]),
        "F": "foo",
    }
)

df2
```
```
     A          B    C  D      E    F
0  1.0 2013-01-02  1.0  3   test  foo
1  1.0 2013-01-02  1.0  3  train  foo
2  1.0 2013-01-02  1.0  3   test  foo
3  1.0 2013-01-02  1.0  3  train  foo
```
데이터프레임의 열들은 서로 다른 자료형을 가질 수 있다.
```python
df2.dtypes
```
```
A          float64
B    datetime64[s]
C          float32
D            int32
E         category
F           object
dtype: object
```

## 데이터 보기
`DataFrame.head()`와 `DataFrame.tail()`을 사용해 각각 데이터프레임의 상단과 하단의 데이터를 볼 수 있다.
```python
df.head()
```
```
                   A         B         C         D
2013-01-01  0.469112 -0.282863 -1.509059 -1.135632
2013-01-02  1.212112 -0.173215  0.119209 -1.044236
2013-01-03 -0.861849 -2.104569 -0.494929  1.071804
2013-01-04  0.721555 -0.706771 -1.039575  0.271860
```
```python
df.tail(3)
```
```
                   A         B         C         D
2013-01-04  0.721555 -0.706771 -1.039575  0.271860
2013-01-05 -0.424972  0.567020  0.276232 -1.087401
2013-01-06 -0.673690  0.113648 -1.478427  0.524988
```
`DataFrame.index`와 `DataFrame.columns`로 데이터프레임의 행과 열을 각각 확인할 수 있다.
```python
df.index
```
```
DatetimeIndex(['2013-01-01', '2013-01-02', '2013-01-03', '2013-01-04',
               '2013-01-05', '2013-01-06'],
              dtype='datetime64[ns]', freq='D')
```
```python
df.columns
```
```
Out[16]: Index(['A', 'B', 'C', 'D'], dtype='object')
```
`DataFrame.to_numpy()`를 사용해 데이터프레임을 행과 열 레이블이 없는 넘파이 표현으로 바꿀 수 있다.
```python
df.to_numpy()
```
```
array([[ 0.4691, -0.2829, -1.5091, -1.1356],
       [ 1.2121, -0.1732,  0.1192, -1.0442],
       [-0.8618, -2.1046, -0.4949,  1.0718],
       [ 0.7216, -0.7068, -1.0396,  0.2719],
       [-0.425 ,  0.567 ,  0.2762, -1.0874],
       [-0.6737,  0.1136, -1.4784,  0.525 ]])
```
`describe()`는 데이터의 빠른 요약을 보여준다.
```python
df.describe()
```
```
              A         B         C         D
count  6.000000  6.000000  6.000000  6.000000
mean   0.073711 -0.431125 -0.687758 -0.233103
std    0.843157  0.922818  0.779887  0.973118
min   -0.861849 -2.104569 -1.509059 -1.135632
25%   -0.611510 -0.600794 -1.368714 -1.076610
50%    0.022070 -0.228039 -0.767252 -0.386188
75%    0.658444  0.041933 -0.034326  0.461706
max    1.212112  0.567020  0.276232  1.071804
```
`T`를 사용해 데이터프레임을 전치할 수 있다.
```python
df.T
```
```
   2013-01-01  2013-01-02  2013-01-03  2013-01-04  2013-01-05  2013-01-06
A    0.469112    1.212112   -0.861849    0.721555   -0.424972   -0.673690
B   -0.282863   -0.173215   -2.104569   -0.706771    0.567020    0.113648
C   -1.509059    0.119209   -0.494929   -1.039575    0.276232   -1.478427
D   -1.135632   -1.044236    1.071804    0.271860   -1.087401    0.524988
```
`DataFrame.sort_index()`는 선택한 축으로 정렬한다. 0은 행, 1은 열
```python
df.sort_index(axis=1, ascending=False)
```
```
                   D         C         B         A
2013-01-01 -1.135632 -1.509059 -0.282863  0.469112
2013-01-02 -1.044236  0.119209 -0.173215  1.212112
2013-01-03  1.071804 -0.494929 -2.104569 -0.861849
2013-01-04  0.271860 -1.039575 -0.706771  0.721555
2013-01-05 -1.087401  0.276232  0.567020 -0.424972
2013-01-06  0.524988 -1.478427  0.113648 -0.673690
```
`DataFrame.sort_values()`는 값을 기준으로 정렬한다.
```python
df.sort_values(by="B")
```
```
                   A         B         C         D
2013-01-03 -0.861849 -2.104569 -0.494929  1.071804
2013-01-04  0.721555 -0.706771 -1.039575  0.271860
2013-01-01  0.469112 -0.282863 -1.509059 -1.135632
2013-01-02  1.212112 -0.173215  0.119209 -1.044236
2013-01-06 -0.673690  0.113648 -1.478427  0.524988
2013-01-05 -0.424972  0.567020  0.276232 -1.087401
```