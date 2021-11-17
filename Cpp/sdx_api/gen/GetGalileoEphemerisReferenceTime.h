#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetGalileoEphemerisReferenceTime is deprecated since 21.3. You may use GetEphemerisReferenceTimeForSV.
    /// 
    /// Get the Galileo ephemeris reference time
    ///
    /// Name Type Description
    /// ---- ---- --------------------------
    /// Prn  int  Satellite PRN number 1..36
    ///

    class GetGalileoEphemerisReferenceTime;
    typedef std::shared_ptr<GetGalileoEphemerisReferenceTime> GetGalileoEphemerisReferenceTimePtr;
    
    
    class GetGalileoEphemerisReferenceTime : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGalileoEphemerisReferenceTime();

      GetGalileoEphemerisReferenceTime(int prn);
  
      static GetGalileoEphemerisReferenceTimePtr create(int prn);
      static GetGalileoEphemerisReferenceTimePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
  }
}

