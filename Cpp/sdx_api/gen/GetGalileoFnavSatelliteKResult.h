#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGalileoFnavSatelliteK.
    ///
    /// Name Type Description
    /// ---- ---- -----------------------
    /// Prn  int  Satellite PRN number
    /// K    int  Satellite K PRN number.
    ///

    class GetGalileoFnavSatelliteKResult;
    typedef std::shared_ptr<GetGalileoFnavSatelliteKResult> GetGalileoFnavSatelliteKResultPtr;
    
    
    class GetGalileoFnavSatelliteKResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGalileoFnavSatelliteKResult();

      GetGalileoFnavSatelliteKResult(int prn, int k);

      GetGalileoFnavSatelliteKResult(CommandBasePtr relatedCommand, int prn, int k);

      static GetGalileoFnavSatelliteKResultPtr create(int prn, int k);

      static GetGalileoFnavSatelliteKResultPtr create(CommandBasePtr relatedCommand, int prn, int k);
      static GetGalileoFnavSatelliteKResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** k ****
      int k() const;
      void setK(int k);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetGalileoFnavSatelliteKResult);
  }
}

