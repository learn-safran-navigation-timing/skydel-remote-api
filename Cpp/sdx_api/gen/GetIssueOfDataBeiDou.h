#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get BeiDou Issue of data, Ephemeris (IODE) and Issue of data, Clock (IODC)
    ///
    /// 
    ///

    class GetIssueOfDataBeiDou;
    typedef std::shared_ptr<GetIssueOfDataBeiDou> GetIssueOfDataBeiDouPtr;
    
    
    class GetIssueOfDataBeiDou : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIssueOfDataBeiDou();

      static GetIssueOfDataBeiDouPtr create();
      static GetIssueOfDataBeiDouPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

