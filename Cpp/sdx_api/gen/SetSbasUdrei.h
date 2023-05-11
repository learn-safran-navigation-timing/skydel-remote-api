#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetSbasUdrei is deprecated since 22.2. You may use SetUdreiForSV.
    /// 
    /// Set the global UDREI value transmitted by SBAS
    ///
    /// Name  Type Description
    /// ----- ---- ---------------
    /// Udrei int  The UDREI value
    ///

    class SetSbasUdrei;
    typedef std::shared_ptr<SetSbasUdrei> SetSbasUdreiPtr;
    
    
    class SetSbasUdrei : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;

      static const char* const Deprecated;


      SetSbasUdrei();

      SetSbasUdrei(int udrei);

      static SetSbasUdreiPtr create(int udrei);
      static SetSbasUdreiPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual Sdx::optional<std::string> deprecated() const override;

      virtual int executePermission() const override;


      // **** udrei ****
      int udrei() const;
      void setUdrei(int udrei);
    };
    
  }
}

