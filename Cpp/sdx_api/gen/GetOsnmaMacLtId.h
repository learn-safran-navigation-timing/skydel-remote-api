#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get OSNMA MAC look-up table ID.
    ///
    /// 
    ///

    class GetOsnmaMacLtId;
    typedef std::shared_ptr<GetOsnmaMacLtId> GetOsnmaMacLtIdPtr;
    
    
    class GetOsnmaMacLtId : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetOsnmaMacLtId();

      static GetOsnmaMacLtIdPtr create();
      static GetOsnmaMacLtIdPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

