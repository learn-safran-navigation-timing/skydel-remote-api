#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command IsQzssSatMotionFixed is deprecated since 20.9. You may use IsSatMotionFixed.
    /// 
    /// Tells if the satellite is fixed (True) or not fixed (false).
    ///
    /// Name Type Description
    /// ---- ---- ----------------------
    /// SvId int  Satellite SV ID number
    ///

    class IsQzssSatMotionFixed;
    typedef std::shared_ptr<IsQzssSatMotionFixed> IsQzssSatMotionFixedPtr;
    
    
    class IsQzssSatMotionFixed : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsQzssSatMotionFixed();

      IsQzssSatMotionFixed(int svId);
  
      static IsQzssSatMotionFixedPtr create(int svId);
      static IsQzssSatMotionFixedPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

