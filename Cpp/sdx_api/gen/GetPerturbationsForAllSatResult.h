#pragma once

#include <memory>
#include "command_result.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetPerturbationsForAllSat
    ///
    /// Name   Type         Description
    /// ------ ------------ ---------------------------------------------
    /// System string       "GPS", "Galileo", "BeiDou", "QZSS" or "NavIC"
    /// Crs    array double Crs (meter)
    /// Crc    array double Crc (meter)
    /// Cis    array double Cis (rad)
    /// Cic    array double Cic (rad)
    /// Cus    array double Cus (rad)
    /// Cuc    array double Cuc (rad)
    ///

    class GetPerturbationsForAllSatResult;
    typedef std::shared_ptr<GetPerturbationsForAllSatResult> GetPerturbationsForAllSatResultPtr;
    
    
    class GetPerturbationsForAllSatResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPerturbationsForAllSatResult();

      GetPerturbationsForAllSatResult(CommandBasePtr relatedCommand, const std::string& system, const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc);
  
      static GetPerturbationsForAllSatResultPtr create(CommandBasePtr relatedCommand, const std::string& system, const std::vector<double>& crs, const std::vector<double>& crc, const std::vector<double>& cis, const std::vector<double>& cic, const std::vector<double>& cus, const std::vector<double>& cuc);
      static GetPerturbationsForAllSatResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


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

