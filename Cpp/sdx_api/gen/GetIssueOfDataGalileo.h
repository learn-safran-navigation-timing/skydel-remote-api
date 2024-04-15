#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Galileo Issue of data, Navigation (IODNAV) and Issue of data, Almanac (IODA)
    ///
    /// 
    ///

    class GetIssueOfDataGalileo;
    typedef std::shared_ptr<GetIssueOfDataGalileo> GetIssueOfDataGalileoPtr;
    
    
    class GetIssueOfDataGalileo : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetIssueOfDataGalileo();

      static GetIssueOfDataGalileoPtr create();
      static GetIssueOfDataGalileoPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

