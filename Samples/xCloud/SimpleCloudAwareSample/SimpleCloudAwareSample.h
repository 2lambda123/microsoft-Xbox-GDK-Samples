//--------------------------------------------------------------------------------------
// SimpleCloudAwareSample.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

#include "DeviceResources.h"
#include "StepTimer.h"

#include "xgamestreaming.h"

#define TOUCHSIZE 24

const int c_maxClients = 4;

enum CurrentOverlay
{
    standard_controller,
    driving,
    fighting,
    first_person_shooter,
    platformer_simple,
    platformer,
    Off
};

struct ClientDevice
{
    XGameStreamingClientId id;
    bool validOverlay;
    bool smallScreen;

    ClientDevice()
    {
        id = XGameStreamingNullClientId;
        validOverlay = false;
        smallScreen = false;
    }
};

// A basic sample implementation that creates a D3D12 device and
// provides a render loop.
class Sample
{
public:

    Sample() noexcept(false);
    virtual ~Sample();

    Sample(Sample&&) = delete;
    Sample& operator= (Sample&&) = delete;

    Sample(Sample const&) = delete;
    Sample& operator= (Sample const&) = delete;

    // Initialization and management
    void Initialize(HWND window);

    // Basic render loop
    void Tick();

    // Messages
    void OnSuspending();
    void OnResuming();
    void OnConstrained() {}
    void OnUnConstrained() {}

    // Properties
    bool RequestHDRMode() const noexcept { return m_deviceResources ? (m_deviceResources->GetDeviceOptions() & DX::DeviceResources::c_EnableHDR) != 0 : false; }

    void UpdateClientState();

    ClientDevice m_clients[c_maxClients];

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();

    void CreateDeviceDependentResources();
    void CreateWindowSizeDependentResources();

    void XM_CALLCONV DrawTouch(uint64_t id, float x, float y);

    // Device resources.
    std::unique_ptr<DX::DeviceResources>        m_deviceResources;

    // Rendering loop timer.
    uint64_t                                    m_frame;
    DX::StepTimer                               m_timer;

    // Input device.
    Microsoft::WRL::ComPtr<IGameInput>			m_gameInput;
    Microsoft::WRL::ComPtr<IGameInputReading>   m_reading;
    std::wstring			                    m_typeString;
    std::wstring			                    m_buttonString;
    double						                m_leftTrigger;
    double                                      m_rightTrigger;
    double                                      m_leftStickX;
    double                                      m_leftStickY;
    double                                      m_rightStickX;
    double                                      m_rightStickY;

    std::map<uint64_t, DirectX::XMFLOAT2>       m_touchPoints;
    std::mutex							        m_touchListLock;
    bool										m_overlayDown;
    CurrentOverlay                              m_currentOverlay;
    double                                      m_resetTime;
    bool                                        m_streaming;
    bool                                        m_validOverlay;
    XTaskQueueRegistrationToken                 m_token;
    XTaskQueueHandle                            m_queue;

    // DirectXTK objects.
    std::unique_ptr<DirectX::GraphicsMemory>    m_graphicsMemory;
    std::unique_ptr<DirectX::DescriptorHeap>    m_resourceDescriptors;

    // UI
    std::unique_ptr<DirectX::SpriteBatch>       m_batch;
    DirectX::SpriteFont*                        m_font;
    std::unique_ptr<DirectX::SpriteFont>        m_localFont;
    std::unique_ptr<DirectX::SpriteFont>        m_remoteFont;
    std::unique_ptr<DirectX::SpriteFont>        m_ctrlFont;

    Microsoft::WRL::ComPtr<ID3D12Resource>      m_circleTexture;
    Microsoft::WRL::ComPtr<ID3D12Resource>      m_background;

    enum Descriptors
    {
        PrintLocalFont,
        PrintRemoteFont,
        ControllerFont,
        Touch,
        Background,
        Count,
    };
};
