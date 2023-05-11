#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get QZSS Issue of data, Ephemeris (IODE) and Issue of data, Clock (IODC)
    ///
    /// 
    ///

    class GetIssueOfDataQzss;
    typedef std::shared_ptr<GetIssueOfDataQzss> GetIssueOfDataQzssPtr;
    
    
    class GetIssueOfDataQzss : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetIssueOfDataQzss();

      static GetIssueOfDataQzssPtr create();
      static GetIssueOfDataQzssPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

