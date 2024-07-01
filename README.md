# MIPS
A simple MIPS processor implemented with logic gates

# Component I/F 설명
- 모든 부품은 Component 를 상속 받는다.
- 모든 내부 component 입력 값을 설정 후 동시에 실행
  - propagation delay 는 최소 run() 1회 이상
    - 1회 : gate(and, or, nand, xor, not 등)
    - 2회 : latch, full adder 등

## 동작 순서
- 1단계 : 핀 입력 설정
- 2단계 : run 호출
  - return : 내부 component 및 최종 출력 값 변경 여부
- 3단계 : 출력 값 사용

## 상속 구현
### setComponent()
- 사용 component 를 내부 vector components 에 추가
- 단, 사용 component 가 없을 경우 빈 함수
  - EX> gate
### setInputComponent()
- 각 component 간의 입력 값 연결
- 단, 사용 component 가 없을 경우 빈 함수
### setOutputComponent()
- 각 component 간의 출력 값 연결
