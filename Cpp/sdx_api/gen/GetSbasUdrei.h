#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetSbasUdrei is deprecated since 22.2. You may use GetUdreiForSV.
    /// 
    /// Get the global UDREI value transmitted by SBAS
    ///
    /// 
    ///

    class GetSbasUdrei;
    typedef std::shared_ptr<GetSbasUdrei> GetSbasUdreiPtr;
    
    
    class GetSbasUdrei : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;

      static const char* const Deprecated;


      GetSbasUdrei();

      static GetSbasUdreiPtr create();
      static GetSbasUdreiPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual Sdx::optional<std::string> deprecated() const override;

      virtual int executePermission() const override;
    };
    
  }
}

