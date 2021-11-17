#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsSatelliteSignalHealth.
    ///
    /// Name   Type Description
    /// ------ ---- --------------------------
    /// Prn    int  Satellite PRN number 1..32
    /// Health int  Signal health 0..31
    ///

    class GetGpsSatelliteSignalHealthResult;
    typedef std::shared_ptr<GetGpsSatelliteSignalHealthResult> GetGpsSatelliteSignalHealthResultPtr;
    
    
    class GetGpsSatelliteSignalHealthResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsSatelliteSignalHealthResult();

      GetGpsSatelliteSignalHealthResult(CommandBasePtr relatedCommand, int prn, int health);
  
      static GetGpsSatelliteSignalHealthResultPtr create(CommandBasePtr relatedCommand, int prn, int health);
      static GetGpsSatelliteSignalHealthResultPtr dynamicCast(CommandBasePtr ptr);
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

