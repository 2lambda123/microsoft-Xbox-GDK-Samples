# 게임 패드 진동 샘플

*이 샘플은 Microsoft 게임 개발 키트 미리 보기(2019년 11월)와
호환됩니다.*

# 

# 설명

이 샘플에서는 Xbox One의 게임 패드에서 진동을 사용하는 방법을 보여
줍니다.

![](./media/image1.png)

# 샘플 빌드하기

Xbox One 개발 키트를 사용하는 경우 활성 솔루션 플랫폼을
Gaming.Xbox.XboxOne.x64로 설정하세요.

Project Scarlett을 사용하는 경우 활성 솔루션 플랫폼을
Gaming.Xbox.Scarlett.x64로 설정하세요.

*자세한 내용은 GDK 문서에서* 샘플 실행하기*를 참조하세요.*

# 샘플 사용

D-패드 왼쪽과 오른쪽을 사용하여 다른 진동 예제 간을 순환합니다. 대부분의
예제에서 트리거를 사용하여 진동 크기를 늘립니다.

# 구현 참고 사항

이 샘플에서는 GameInput API를 사용하여 Xbox One 게임 패드에서 진동
수준을 설정하는 방법을 보여 줍니다.

# 업데이트 기록

초기 릴리스 2019년 4월

**SetRumbleState**에 대한 경미한 주요 변경 내용으로 2019년 6월에
업데이트되었습니다.

2020년 2월: GameInput API에 대한 변경 내용으로 업데이트되었습니다.

# 개인정보처리방침

샘플을 컴파일하고 실행할 때 샘플 사용을 추적하는 데 도움이 되도록 샘플
실행 파일의 파일 이름이 Microsoft에 전송됩니다. 이 데이터 수집을
옵트아웃하려면 Main.cpp에서 \"샘플 사용 원격 분석\"이라고 레이블이
지정된 코드 블록을 제거할 수 있습니다.

Microsoft의 개인 정보 보호 정책에 대한 자세한 내용은 [Microsoft
개인정보처리방침](https://privacy.microsoft.com/en-us/privacystatement/)을
참조하세요.