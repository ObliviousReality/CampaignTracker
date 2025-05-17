#pragma once

#include "Render/Common/Window.hpp"

#include "Render/Win32/imgui_impl_dx11.hpp"
#include "Render/Win32/imgui_impl_win32.hpp"
#include "imgui.h"

// DirectX
#include <d3d11.h>
#include <d3dcompiler.h>
#include <stdio.h>
#include <tchar.h>

#ifdef _MSC_VER
#    pragma comment(lib, "d3dcompiler") // Automatically link with d3dcompiler.lib as we are using D3DCompile() below.
#endif

class WinWindow : public Window
{
public:
    WinWindow() : Window() {}

    void createWindow() override;

    void initImGui() override;

    bool pollUpdates() override;
    void startFrame() override;
    void endFrame() override;

private:

    HWND window = nullptr;

    bool CreateDeviceD3D(HWND hWnd);
    void CleanupDeviceD3D();
    void CreateRenderTarget();
    void CleanupRenderTarget();

    ID3D11Device * g_pd3dDevice = nullptr;
    ID3D11DeviceContext * g_pd3dDeviceContext = nullptr;
    IDXGISwapChain * g_pSwapChain = nullptr;
    bool g_SwapChainOccluded = false;
    ID3D11RenderTargetView * g_mainRenderTargetView = nullptr;
};