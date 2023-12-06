//--------------------------------------------------------------------------------------
// SimpleLogManager.h
//
// Advanced Technology Group (ATG)
// Copyright (C) Microsoft Corporation. All rights reserved.
//--------------------------------------------------------------------------------------

#pragma once

class SimpleLogManager
{
public:
    SimpleLogManager() noexcept(false);
    ~SimpleLogManager();
    void Log(const std::string& text);
    void LogFailedHR(HRESULT hr, const std::string& functionName = "");
    void ClearLogQueue();
    std::vector<std::string> GetLogQueue();
    size_t QueueSize();
    std::mutex& GetMutex();
    std::vector<std::string> FlushLogQueue();

private:
    std::mutex                                  m_logMutex;
    std::vector<std::string>                    m_logQueue;
};

