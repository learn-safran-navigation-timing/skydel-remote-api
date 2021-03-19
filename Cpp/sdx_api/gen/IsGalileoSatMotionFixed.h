#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GalileoSatMotionFixed is deprecated since 21.3. You may use SatMotionFixed.
    /// 
    /// Tells if the satellite is fixed (True) or not fixed (false).
    ///
    /// Name Type Description
    /// ---- ---- --------------------
    /// Prn  int  Satellite PRN number
    ///

    class IsGalileoSatMotionFixed;
    typedef std::shared_ptr<IsGalileoSatMotionFixed> IsGalileoSatMotionFixedPtr;
    
    
    class IsGalileoSatMotionFixed : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsGalileoSatMotionFixed();

      IsGalileoSatMotionFixed(int prn);
  
      static IsGalileoSatMotionFixedPtr create(int prn);
      static IsGalileoSatMotionFixedPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

