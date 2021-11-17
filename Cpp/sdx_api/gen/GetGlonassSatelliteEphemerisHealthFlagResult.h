#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGlonassSatelliteEphemerisHealthFlag.
    ///
    /// Name   Type Description
    /// ------ ---- --------------------------------------
    /// Prn    int  Satellite PRN number 1..24
    /// Health bool Status, false = OK, true = Malfunction
    ///

    class GetGlonassSatelliteEphemerisHealthFlagResult;
    typedef std::shared_ptr<GetGlonassSatelliteEphemerisHealthFlagResult> GetGlonassSatelliteEphemerisHealthFlagResultPtr;
    
    
    class GetGlonassSatelliteEphemerisHealthFlagResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGlonassSatelliteEphemerisHealthFlagResult();

      GetGlonassSatelliteEphemerisHealthFlagResult(CommandBasePtr relatedCommand, int prn, bool health);
  
      static GetGlonassSatelliteEphemerisHealthFlagResultPtr create(CommandBasePtr relatedCommand, int prn, bool health);
      static GetGlonassSatelliteEphemerisHealthFlagResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** health ****
      bool health() const;
      void setHealth(bool health);
    };
  }
}

