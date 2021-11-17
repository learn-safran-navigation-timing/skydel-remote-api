#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGpsEphemerisReferenceTime is deprecated since 21.3. You may use GetEphemerisReferenceTimeForSV.
    /// 
    /// Get the GPS ephemeris reference time
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..32
    ///

    class GetGpsEphemerisReferenceTime;
    typedef std::shared_ptr<GetGpsEphemerisReferenceTime> GetGpsEphemerisReferenceTimePtr;
    
    
    class GetGpsEphemerisReferenceTime : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsEphemerisReferenceTime();

      GetGpsEphemerisReferenceTime(int prn);
  
      static GetGpsEphemerisReferenceTimePtr create(int prn);
      static GetGpsEphemerisReferenceTimePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

