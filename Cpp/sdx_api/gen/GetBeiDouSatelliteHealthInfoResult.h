#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetBeiDouSatelliteHealthInfo.
    ///
    /// Name   Type Description
    /// ------ ---- -------------------------------------------------------------------------
    /// Prn    int  Satellite PRN number 1..30
    /// Health int  Health Info, 9-bit integer : 0, 2, 64, 66, 128, 130, 192, 194, 256 or 511
    ///

    class GetBeiDouSatelliteHealthInfoResult;
    typedef std::shared_ptr<GetBeiDouSatelliteHealthInfoResult> GetBeiDouSatelliteHealthInfoResultPtr;
    
    
    class GetBeiDouSatelliteHealthInfoResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouSatelliteHealthInfoResult();

      GetBeiDouSatelliteHealthInfoResult(CommandBasePtr relatedCommand, int prn, int health);
  
      static GetBeiDouSatelliteHealthInfoResultPtr create(CommandBasePtr relatedCommand, int prn, int health);
      static GetBeiDouSatelliteHealthInfoResultPtr dynamicCast(CommandBasePtr ptr);
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

