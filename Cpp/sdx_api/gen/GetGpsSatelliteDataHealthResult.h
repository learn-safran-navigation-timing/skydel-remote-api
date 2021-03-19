#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsSatelliteDataHealth
    ///
    /// Name   Type Description
    /// ------ ---- --------------------------
    /// Prn    int  Satellite PRN number 1..32
    /// Health int  Data health 0..7
    ///

    class GetGpsSatelliteDataHealthResult;
    typedef std::shared_ptr<GetGpsSatelliteDataHealthResult> GetGpsSatelliteDataHealthResultPtr;
    
    
    class GetGpsSatelliteDataHealthResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsSatelliteDataHealthResult();

      GetGpsSatelliteDataHealthResult(CommandBasePtr relatedCommand, int prn, int health);
  
      static GetGpsSatelliteDataHealthResultPtr create(CommandBasePtr relatedCommand, int prn, int health);
      static GetGpsSatelliteDataHealthResultPtr dynamicCast(CommandBasePtr ptr);
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

