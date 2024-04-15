#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get GPS Issue of data, Ephemeris (IODE) and Issue of data, Clock (IODC)
    ///
    /// 
    ///

    class GetIssueOfData;
    typedef std::shared_ptr<GetIssueOfData> GetIssueOfDataPtr;
    
    
    class GetIssueOfData : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIssueOfData();

      static GetIssueOfDataPtr create();
      static GetIssueOfDataPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

