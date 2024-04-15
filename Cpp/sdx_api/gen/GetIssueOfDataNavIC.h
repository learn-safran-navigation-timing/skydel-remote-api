#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get NavIC Issue of data, Ephemeris and Clock (IODEC)
    ///
    /// 
    ///

    class GetIssueOfDataNavIC;
    typedef std::shared_ptr<GetIssueOfDataNavIC> GetIssueOfDataNavICPtr;
    
    
    class GetIssueOfDataNavIC : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIssueOfDataNavIC();

      static GetIssueOfDataNavICPtr create();
      static GetIssueOfDataNavICPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

