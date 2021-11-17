#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command IsGpsSatMotionFixed is deprecated since 21.3. You may use IsSatMotionFixed.
    /// 
    /// Tells if the satellite is fixed (True) or not fixed (false).
    ///
    /// Name Type Description
    /// ---- ---- --------------------
    /// Prn  int  Satellite PRN number
    ///

    class IsGpsSatMotionFixed;
    typedef std::shared_ptr<IsGpsSatMotionFixed> IsGpsSatMotionFixedPtr;
    
    
    class IsGpsSatMotionFixed : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsGpsSatMotionFixed();

      IsGpsSatMotionFixed(int prn);
  
      static IsGpsSatMotionFixedPtr create(int prn);
      static IsGpsSatMotionFixedPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

