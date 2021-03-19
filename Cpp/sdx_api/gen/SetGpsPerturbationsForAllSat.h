#pragma once

#include <memory>
#include "command_base.h"
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GpsPerturbationsForAllSat is deprecated since 21.3. You may use PerturbationsForAllSat.
    /// 
    /// Set GPS orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) for all satellites.
    /// All parameters are zero based index (index 0 => PRN 1, index 1 => PRN 2, etc)
    ///
    /// Name Type         Description
    /// ---- ------------ -----------
    /// Crs  array double Crs (meter)
    /// Crc  array double Crc (meter)
    /// Cis  array double Cis (rad)
    /// Cic  array double Cic (rad)
    /// Cus  array double Cus (rad)
    /// Cuc  array double Cuc (rad)
    ///

    class SetGpsPerturbationsForAllSat;
    typedef std::shared_ptr<SetGpsPerturbationsForAllSat> SetGpsPerturbationsForAllSatPtr;
    
    
    class SetGpsPerturbationsForAllSat : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGpsPerturbationsForAllSat();

      SetGpsPerturbationsForAllSat(const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc);
  
      static SetGpsPerturbationsForAllSatPtr create(const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc);
      static SetGpsPerturbationsForAllSatPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** crs ****
      std::vector<double> crs() const;
      void setCrs(const std::vector<double>& crs);


      // **** crc ****
      std::vector<double> crc() const;
      void setCrc(const std::vector<double>& crc);


      // **** cis ****
      std::vector<double> cis() const;
      void setCis(const std::vector<double>& cis);


      // **** cic ****
      std::vector<double> cic() const;
      void setCic(const std::vector<double>& cic);


      // **** cus ****
      std::vector<double> cus() const;
      void setCus(const std::vector<double>& cus);


      // **** cuc ****
      std::vector<double> cuc() const;
      void setCuc(const std::vector<double>& cuc);
    };
  }
}

