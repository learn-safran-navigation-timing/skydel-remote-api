#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetBeiDouSatelliteHealthStatus
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------------------------
    /// Prn    int  Satellite PRN number 1..30
    /// Health int  Health Info, 2-bit integer : 0, 1, 2 or 3
    ///

    class GetBeiDouSatelliteHealthStatusResult;
    typedef std::shared_ptr<GetBeiDouSatelliteHealthStatusResult> GetBeiDouSatelliteHealthStatusResultPtr;
    
    
    class GetBeiDouSatelliteHealthStatusResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouSatelliteHealthStatusResult();

      GetBeiDouSatelliteHealthStatusResult(CommandBasePtr relatedCommand, int prn, int health);
  
      static GetBeiDouSatelliteHealthStatusResultPtr create(CommandBasePtr relatedCommand, int prn, int health);
      static GetBeiDouSatelliteHealthStatusResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** health ****
      int health() const;
      void setHealth(int health);
    };
  }
}

