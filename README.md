# QT와 인터프리터 패턴을 이용한 계산기 만들기

## 인터프리터 패턴 적용 계기
[QT계산기 회고](https://velog.io/@14opqo41/QT-%EA%B3%84%EC%82%B0%EA%B8%B0-%ED%9A%8C%EA%B3%A0-%ED%95%9C%ED%99%94%EB%B9%84%EC%A0%84-VEDA-1%EA%B8%B0) 를 하면서 수 많은 IF문을 발견함  
계산기 코드를 만드는 데 있어서 수 많은 IF문이 사용된 나머지 가독성이 좋아지지 않아 보였음  
사칙연산 우선순위를 추가하려고 함  
[Velog에서 더 자세한 이야기 보기](https://velog.io/@14opqo41/QT%EA%B3%84%EC%82%B0%EA%B8%B0-%EA%B0%9C%EC%84%A0%ED%95%98%EA%B8%B0)

## 패턴 설계 구조
<img src="https://github.com/user-attachments/assets/0b529a4f-a9a8-4b73-8dfd-9d30bf408abb" width="80%" height="80%"/>

## 실행 화면 
<img src="https://github.com/user-attachments/assets/9889ae38-7531-45c3-9c8e-1882c485e737" width="300" height="400"/>

## 실행 방법 
CMake또는  직접 소스코드 빌드 후 실행
