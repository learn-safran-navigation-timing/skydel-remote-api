#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGlonassSatelliteAlmanacUnhealthyFlag.
    ///
    /// Name   Type Description
    /// ------ ---- ----------------------------------------------------------
    /// Prn    int  Satellite PRN number 1..24
    /// Health bool Status, false = Non-operability, true = Operability (Good)
    ///

    class GetGlonassSatelliteAlmanacUnhealthyFlagResult;
    typedef std::shared_ptr<GetGlonassSatelliteAlmanacUnhealthyFlagResult> GetGlonassSatelliteAlmanacUnhealthyFlagResultPtr;
    
    
    class GetGlonassSatelliteAlmanacUnhealthyFlagResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGlonassSatelliteAlmanacUnhealthyFlagResult();

      GetGlonassSatelliteAlmanacUnhealthyFlagResult(CommandBasePtr relatedCommand, int prn, bool health);
  
      static GetGlonassSatelliteAlmanacUnhealthyFlagResultPtr create(CommandBasePtr relatedCommand, int prn, bool health);
      static GetGlonassSatelliteAlmanacUnhealthyFlagResultPtr dynamicCast(CommandBasePtr ptr);
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

