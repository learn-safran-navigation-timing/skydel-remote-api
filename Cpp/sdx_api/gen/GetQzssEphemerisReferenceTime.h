#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetQzssEphemerisReferenceTime is deprecated since 20.9. You may use GetEphemerisReferenceTimeForSV.
    /// 
    /// Get the QZSS ephemeris reference time
    ///
    /// Name Type Description
    /// ---- ---- ---------------------
    /// SvId int  Satellite SV ID 1..10
    ///

    class GetQzssEphemerisReferenceTime;
    typedef std::shared_ptr<GetQzssEphemerisReferenceTime> GetQzssEphemerisReferenceTimePtr;
    
    
    class GetQzssEphemerisReferenceTime : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssEphemerisReferenceTime();

      GetQzssEphemerisReferenceTime(int svId);
  
      static GetQzssEphemerisReferenceTimePtr create(int svId);
      static GetQzssEphemerisReferenceTimePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

