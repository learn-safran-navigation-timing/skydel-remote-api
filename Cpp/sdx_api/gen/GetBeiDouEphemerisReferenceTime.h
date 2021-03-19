#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command BeiDouEphemerisReferenceTime is deprecated since 21.3. You may use EphemerisReferenceTimeForSV.
    /// 
    /// Get the BeiDou ephemeris reference time
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..30
    ///

    class GetBeiDouEphemerisReferenceTime;
    typedef std::shared_ptr<GetBeiDouEphemerisReferenceTime> GetBeiDouEphemerisReferenceTimePtr;
    
    
    class GetBeiDouEphemerisReferenceTime : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouEphemerisReferenceTime();

      GetBeiDouEphemerisReferenceTime(int prn);
  
      static GetBeiDouEphemerisReferenceTimePtr create(int prn);
      static GetBeiDouEphemerisReferenceTimePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

