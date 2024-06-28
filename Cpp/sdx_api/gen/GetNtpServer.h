#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the connection parameters for the NTP Server from which the simulator will get the simulation start time.
    ///
    /// 
    ///

    class GetNtpServer;
    typedef std::shared_ptr<GetNtpServer> GetNtpServerPtr;
    
    
    class GetNtpServer : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetNtpServer();

      static GetNtpServerPtr create();
      static GetNtpServerPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

