#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the almanac satellite id for subframe 1 (Parameter K described in ICD 4.2.3 Frame Layout).
    ///
    /// Name Type Description
    /// ---- ---- --------------------
    /// Prn  int  Satellite PRN number
    ///

    class GetGalileoFnavSatelliteK;
    typedef std::shared_ptr<GetGalileoFnavSatelliteK> GetGalileoFnavSatelliteKPtr;
    
    
    class GetGalileoFnavSatelliteK : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGalileoFnavSatelliteK();

      GetGalileoFnavSatelliteK(int prn);

      static GetGalileoFnavSatelliteKPtr create(int prn);
      static GetGalileoFnavSatelliteKPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);
    };
    
  }
}

