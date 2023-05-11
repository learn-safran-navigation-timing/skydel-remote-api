#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the almanac satellite id for subframe 1 (Parameter K described in ICD 4.2.3 Frame Layout).
    ///
    /// Name Type Description
    /// ---- ---- -----------------------
    /// Prn  int  Satellite PRN number
    /// K    int  Satellite K PRN number.
    ///

    class SetGalileoFnavSatelliteK;
    typedef std::shared_ptr<SetGalileoFnavSatelliteK> SetGalileoFnavSatelliteKPtr;
    
    
    class SetGalileoFnavSatelliteK : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGalileoFnavSatelliteK();

      SetGalileoFnavSatelliteK(int prn, int k);

      static SetGalileoFnavSatelliteKPtr create(int prn, int k);
      static SetGalileoFnavSatelliteKPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** k ****
      int k() const;
      void setK(int k);
    };
    
  }
}

