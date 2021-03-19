#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetBeiDouSatelliteAutonomousHealth
    ///
    /// Name   Type Description
    /// ------ ---- -------------------------------------
    /// Prn    int  Satellite PRN number 1..30
    /// Health bool Status, false = Good, true = Not Good
    ///

    class GetBeiDouSatelliteAutonomousHealthResult;
    typedef std::shared_ptr<GetBeiDouSatelliteAutonomousHealthResult> GetBeiDouSatelliteAutonomousHealthResultPtr;
    
    
    class GetBeiDouSatelliteAutonomousHealthResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouSatelliteAutonomousHealthResult();

      GetBeiDouSatelliteAutonomousHealthResult(CommandBasePtr relatedCommand, int prn, bool health);
  
      static GetBeiDouSatelliteAutonomousHealthResultPtr create(CommandBasePtr relatedCommand, int prn, bool health);
      static GetBeiDouSatelliteAutonomousHealthResultPtr dynamicCast(CommandBasePtr ptr);
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

