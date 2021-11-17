#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command IsBeiDouSatMotionFixed is deprecated since 21.3. You may use IsSatMotionFixed.
    /// 
    /// Tells if the satellite is fixed (True) or not fixed (false).
    ///
    /// Name Type Description
    /// ---- ---- --------------------
    /// Prn  int  Satellite PRN number
    ///

    class IsBeiDouSatMotionFixed;
    typedef std::shared_ptr<IsBeiDouSatMotionFixed> IsBeiDouSatMotionFixedPtr;
    
    
    class IsBeiDouSatMotionFixed : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsBeiDouSatMotionFixed();

      IsBeiDouSatMotionFixed(int prn);
  
      static IsBeiDouSatMotionFixedPtr create(int prn);
      static IsBeiDouSatMotionFixedPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

