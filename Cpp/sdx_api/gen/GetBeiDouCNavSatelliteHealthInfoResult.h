#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetBeiDouCNavSatelliteHealthInfo.
    ///
    /// Name   Type Description
    /// ------ ---- ------------------------------------------------------
    /// Prn    int  Satellite PRN number 1..30
    /// Health int  Health Info, 8-bit integer : 0, 32, 64, 96, 128 or 255
    ///

    class GetBeiDouCNavSatelliteHealthInfoResult;
    typedef std::shared_ptr<GetBeiDouCNavSatelliteHealthInfoResult> GetBeiDouCNavSatelliteHealthInfoResultPtr;
    
    
    class GetBeiDouCNavSatelliteHealthInfoResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouCNavSatelliteHealthInfoResult();

      GetBeiDouCNavSatelliteHealthInfoResult(CommandBasePtr relatedCommand, int prn, int health);
  
      static GetBeiDouCNavSatelliteHealthInfoResultPtr create(CommandBasePtr relatedCommand, int prn, int health);
      static GetBeiDouCNavSatelliteHealthInfoResultPtr dynamicCast(CommandBasePtr ptr);
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

